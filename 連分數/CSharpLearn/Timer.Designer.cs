namespace CSharpLearn {
    partial class Timer {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            GetButton = new Button();
            Input = new TextBox();
            ClearButton = new Button();
            SuspendLayout();
            // 
            // GetButton
            // 
            GetButton.Location = new Point(134, 180);
            GetButton.Name = "GetButton";
            GetButton.Size = new Size(130, 42);
            GetButton.TabIndex = 0;
            GetButton.Text = "Get";
            GetButton.UseVisualStyleBackColor = true;
            GetButton.Click += GetButton_Click;
            // 
            // Input
            // 
            Input.Location = new Point(134, 142);
            Input.Name = "Input";
            Input.Size = new Size(130, 23);
            Input.TabIndex = 1;
            Input.TextChanged += Input_TextChanged;
            // 
            // ClearButton
            // 
            ClearButton.Location = new Point(134, 228);
            ClearButton.Name = "ClearButton";
            ClearButton.Size = new Size(130, 41);
            ClearButton.TabIndex = 2;
            ClearButton.Text = "Clear";
            ClearButton.UseVisualStyleBackColor = true;
            ClearButton.Click += ClearButton_Click;
            // 
            // Timer
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(414, 521);
            Controls.Add(ClearButton);
            Controls.Add(Input);
            Controls.Add(GetButton);
            Name = "Timer";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Button GetButton;
        private TextBox Input;
        private Button ClearButton;
    }
}