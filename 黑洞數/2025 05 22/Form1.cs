namespace _2025_05_22 {
    public partial class Form1 : Form {
        int input, max, min, origin, dif;
        int[] a = new int[4];
        public Form1() {
            InitializeComponent();
        }

        private void textBox1_TextChanged( object sender, EventArgs e ) {
            input = int.Parse(textBox1.Text);
        }

        private void GetButton_Click( object sender, EventArgs e ) {
            toArray(input, a);
            do {
                origin = toNum(a);
                sort(a, true);
                max = toNum(a);
                sort(a, false);
                min = toNum(a);
                dif = max - min;
                toArray(dif, a);
            } while(max - min != origin);
            MessageBox.Show("黑洞數: " + origin.ToString());
        } 

        private void sort( int[] a, bool type ) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++)
                    if (type)
                        if (a[j] < a[j + 1])
                            swap(ref a[j], ref a[j + 1]);
                        else
                            continue;
                    else
                        if (a[j] > a[j + 1])
                            swap(ref a[j], ref a[j + 1]);
                        else
                            continue;
        }

        private void toArray(int n, int[] a) {
            for (int i = 3; i >= 0; i--) {
                a[i] = n % 10;
                n = n / 10;
            }
        }

        private void swap(ref int n1, ref int n2) {
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }

        private int toNum( int[] a ) {
            int n = 0;
            for (int i = 0; i < 4; i++) {
                n = n + a[i];
                if (i != 3)
                    n = n * 10;
            }

            return n;
        }
    }
}
