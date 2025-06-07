using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpLearn {
    public partial class Timer : Form {
        private string userInput = "";
        private int[] n = new int[100];
        private int m = 0, c = 0, l;
        private void swap() {
            int temp = c;
            c = m;
            m = temp;
        }
        public Timer() {
            InitializeComponent();
        }

        private void Input_TextChanged(object sender, EventArgs e) {
            userInput = Input.Text;
        }

        private void GetButton_Click(object sender, EventArgs e) {
            if (userInput.Length == 0)
                return;
            n = userInput
                .Split(',')
                .Select(int.Parse)
                .ToArray();
            l = n.Length;
            c = n[l - 2] * n[l - 1] + 1;
            m = n[l - 1];
            if (l > 2)
                swap();
            for (int i = l - 2; i > 0; i--) {
                c = n[i - 1] * m + c;
                if (i > 1)
                    swap();
            }
            MessageBox.Show(c + " / " + m);
        }

        private void ClearButton_Click(object sender, EventArgs e) {
            n = new int[100];
            m = 0;
            c = 0;
            l = 0;
            Input.Clear();
        }
    }
}
