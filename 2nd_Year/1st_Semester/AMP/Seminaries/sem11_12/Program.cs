
using Sem11_12.Model;
using Sem11_12.Model.Validator;
using Sem11_12.Repository;
using Sem11_12.Service;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Security.Cryptography;

namespace Sem11_12
{
    class Program
    {

        static void Main(string[] args)
        {

            //2  - cerinta 1 din pdf sem11-12  extension methods 
            GetAngajatService().FindAllAngajatiGroupedSorted().ForEach(Console.WriteLine);
            Console.WriteLine();

            //2 cate ore dureaza in medie fiecare tip de sarcina
            foreach (KeyValuePair<Dificultate, double> kvp in GetSarcinaService().MediumTime())
            {
                Console.WriteLine("{0} - {1}", kvp.Key.ToString(), kvp.Value);
            }
            Console.WriteLine();

            //3 primii doi cei mai harnici angajati
            var result = GetPontajService().getCeiMaiHarniciAngajati();
            foreach(KeyValuePair<Angajat, double> kvp in result)
            {
                Console.WriteLine("{0} - {1}", kvp.Key.Nume, kvp.Value);
            }

        }

        private static void Task2()
        {
            

        }


        private static AngajatService GetAngajatService()
        {
            //string fileName2 = ConfigurationManager.AppSettings["angajatiFileName"];
            string fileName = "..\\..\\..\\data\\angajati.txt";
            IValidator<Angajat> vali = new AngajatValidator();

            IRepository<string, Angajat> repo1 = new AngajatInFileRepository(vali, fileName);
            AngajatService service = new AngajatService(repo1);
            return service;
        }

        private static SarcinaService GetSarcinaService()
        {
            //string fileName2 = ConfigurationManager.AppSettings["sarciniFileName"];
            string fileName2 = "..\\..\\..\\data\\sarcini.txt";
            IValidator<Sarcina> vali = new SarcinaValidator();

            IRepository<string, Sarcina> repo1 = new SarcinaInFileRepository(vali, fileName2);
            SarcinaService service = new SarcinaService(repo1);
            return service;
        }

        private static PontajService GetPontajService()
        {
            //string fileName2 = ConfigurationManager.AppSettings["pontajeFileName"];
            string fileName2 = "..\\..\\..\\data\\pontaje.txt";
            IValidator<Pontaj> vali = new PontajValidator();

            IRepository<string, Pontaj> repo1 = new PontajInFileRepository(vali, fileName2);
            PontajService service = new PontajService(repo1);
            return service;
        }

    }
}
