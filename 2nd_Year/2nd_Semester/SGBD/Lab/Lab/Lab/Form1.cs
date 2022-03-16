using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab
{
    public partial class Form1 : Form
    {
        SqlConnection conn = new SqlConnection(@"Data Source=DESKTOP-28G44F1\SQLEXPRESS;Initial Catalog=Tenis;Integrated Security=True");
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'tenisDataSet.Turneu' table. You can move, or remove it, as needed.
            this.turneuTableAdapter.Fill(this.tenisDataSet.Turneu);
            // TODO: This line of code loads data into the 'tenisDataSet.TipTurneu' table. You can move, or remove it, as needed.
            this.tipTurneuTableAdapter.Fill(this.tenisDataSet.TipTurneu);
            // TODO: This line of code loads data into the 'tenisDataSet.Circuit' table. You can move, or remove it, as needed.
            this.circuitTableAdapter.Fill(this.tenisDataSet.Circuit);
            // TODO: This line of code loads data into the 'tenisDataSet.Tari' table. You can move, or remove it, as needed.
            this.tariTableAdapter.Fill(this.tenisDataSet.Tari);

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("Salvati?", "Atentie", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                saveButton.PerformClick();
            }
            conn.Close();
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.fKTipTurneuCircu286302ECBindingSource1.EndEdit();
            this.tipTurneuTableAdapter.Update(this.tenisDataSet);

        }
    }
}
