namespace CSharpLearn
{
    public partial class BmiCalculator : Form {

        public BmiCalculator() {
            InitializeComponent();
        }

        private void BmiGetter_Click(object sender, EventArgs e) {
            if (InputHeight.Text.Equals("") || 
                InputWidth.Text.Equals("")) {
                return;
            }

            int width;
            double height, bmi;

            try {
                width = int.Parse(InputWidth.Text);
                height = double.Parse(InputHeight.Text);
            } catch (FormatException) {
                MessageBox.Show("請輸入正確格式");
                return;
            }

            if (height >= 100) // 如果使用者輸入公分 -> 則換算為公尺
                height = height / 100;

            bmi = width / (height * height);
            MessageBox.Show(bmi.ToString());
        }
    }
}
