namespace CSharpLearn
{
    partial class BmiCalculator
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            InputWidth = new TextBox();
            InputHeight = new TextBox();
            BmiGetter = new Button();
            SuspendLayout();
            // 
            // InputWidth
            // 
            InputWidth.Location = new Point(211, 184);
            InputWidth.Name = "InputWidth";
            InputWidth.PlaceholderText = "輸入你的體重";
            InputWidth.Size = new Size(143, 23);
            InputWidth.TabIndex = 0;
            // 
            // InputHeight
            // 
            InputHeight.Location = new Point(211, 233);
            InputHeight.Name = "InputHeight";
            InputHeight.PlaceholderText = "輸入你的身高";
            InputHeight.Size = new Size(143, 23);
            InputHeight.TabIndex = 1;
            // 
            // BmiGetter
            // 
            BmiGetter.Location = new Point(211, 284);
            BmiGetter.Name = "BmiGetter";
            BmiGetter.Size = new Size(110, 35);
            BmiGetter.TabIndex = 2;
            BmiGetter.Text = "Get";
            BmiGetter.UseVisualStyleBackColor = true;
            BmiGetter.Click += BmiGetter_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(551, 638);
            Controls.Add(BmiGetter);
            Controls.Add(InputHeight);
            Controls.Add(InputWidth);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox InputWidth;
        private TextBox InputHeight;
        private Button BmiGetter;
    }
}
