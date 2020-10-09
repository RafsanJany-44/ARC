using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using ConfMatrix;

namespace ConfMatrix
{
    public partial class ConfMat : Form
    {
        public ConfMat()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Calc calculator = new Calc(textBox1.Text, textBox2.Text, textBox4.Text, textBox3.Text);
            acc.Text = calculator.accuracy().ToString();
            prec.Text = calculator.precision().ToString();
            sens.Text = calculator.sensitivity().ToString();
            spec.Text = calculator.specificity().ToString();
            f1.Text = calculator.f1Score().ToString();
            //Debug.WriteLine(calculator.accuracy());
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void acc_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
