using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace Seminar_1_225_SGBD_Console_App
{
    class Program
    {
        static void Main(string[] args)
        {
            //setarea titlului consolei
            Console.Title = "Seminar 1 225 Console App ADO.NET";
            //setarea culorii de fundal a consolei
            Console.BackgroundColor = ConsoleColor.White;
            //setarea culorii caracterelor afisate in consola
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.Clear();
            Console.WriteLine("Hello ADO.NET!");
            try
            {
                string connectionString = @"Server=DESKTOP-01E0F0G\SQLEXPRESS;Database=Seminar1225SGBD;Integrated Security=true;";
                //cream conexiunea la nivelul blocului using
                using(SqlConnection connection = new SqlConnection(connectionString))
                {
                    Console.WriteLine("Starea conexiunii: {0}", connection.State);
                    connection.Open();
                    Console.WriteLine("Starea conexiunii dupa apelul metodei Open(): {0}", connection.State);
                    //inserarea unei inregistrari in tabel
                    SqlCommand insertCommand = new SqlCommand("INSERT INTO AnimaleGradinaZoologica (nume, specie, data_nasterii) " +
                        "VALUES (@nume, @specie, @data_nasterii);", connection);
                    insertCommand.Parameters.AddWithValue("@nume", "Bob");
                    insertCommand.Parameters.AddWithValue("@specie", "maimuta capucin");
                    DateTime dataDeAzi = DateTime.Now;
                    insertCommand.Parameters.AddWithValue("@data_nasterii", dataDeAzi);
                    int insertRowCount = insertCommand.ExecuteNonQuery();
                    Console.WriteLine("Numarul de inregistrari inserate: {0}", insertRowCount);
                    //citirea si afisarea datelor din tabel in consola
                    SqlCommand selectCommand = new SqlCommand("SELECT nume, specie FROM AnimaleGradinaZoologica;", connection);
                    SqlDataReader reader = selectCommand.ExecuteReader();
                    if(reader.HasRows)
                    {
                        Console.WriteLine("Afisarea datelor din tabelul AnimaleGradinaZoologica");
                        while(reader.Read())
                        {
                            Console.WriteLine("{0}\t{1}", reader.GetString(0), reader.GetString(1));
                        }
                    }
                    reader.Close();
                    //actualizarea datelor din tabel
                    SqlCommand updateCommand = new SqlCommand("UPDATE AnimaleGradinaZoologica SET specie=@nouaspecie " +
                        "WHERE nume=@nume;", connection);
                    updateCommand.Parameters.AddWithValue("@nouaspecie", "bonobo");
                    updateCommand.Parameters.AddWithValue("@nume", "Bob");
                    updateCommand.ExecuteNonQuery();
                    //citirea si afisarea datelor din tabel in consola dupa update
                    reader = selectCommand.ExecuteReader();
                    if (reader.HasRows)
                    {
                        Console.WriteLine("Afisarea datelor dupa actualizare din tabelul AnimaleGradinaZoologica");
                        while (reader.Read())
                        {
                            Console.WriteLine("{0}\t{1}", reader.GetString(0), reader.GetString(1));
                        }
                    }
                    reader.Close();
                    //stergerea datelor din tabel
                    SqlCommand deleteCommand = new SqlCommand("DELETE FROM AnimaleGradinaZoologica WHERE nume=@nume", connection);
                    deleteCommand.Parameters.AddWithValue("@nume", "Bob");
                    int deleteRowCount = deleteCommand.ExecuteNonQuery();
                    Console.WriteLine("Numarul de inregistrari sterse este {0}", deleteRowCount);
                }
            }
            catch(Exception ex)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("Mesajul exceptiei care ne-a adus in catch este: {0}", ex.Message);
            }
        }
    }
}
