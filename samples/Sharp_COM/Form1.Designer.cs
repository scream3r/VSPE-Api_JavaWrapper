namespace VSPE_API_Test
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.CreateDevice = new System.Windows.Forms.Button();
            this.Info = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // CreateDevice
            // 
            this.CreateDevice.Location = new System.Drawing.Point(31, 12);
            this.CreateDevice.Name = "CreateDevice";
            this.CreateDevice.Size = new System.Drawing.Size(159, 23);
            this.CreateDevice.TabIndex = 0;
            this.CreateDevice.Text = "Create device";
            this.CreateDevice.UseVisualStyleBackColor = true;
            this.CreateDevice.Click += new System.EventHandler(this.CreateDevice_Click);
            // 
            // Info
            // 
            this.Info.Location = new System.Drawing.Point(31, 41);
            this.Info.Name = "Info";
            this.Info.Size = new System.Drawing.Size(159, 23);
            this.Info.TabIndex = 0;
            this.Info.Text = "Info";
            this.Info.UseVisualStyleBackColor = true;
            this.Info.Click += new System.EventHandler(this.Info_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(28, 81);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "label1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(445, 103);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Info);
            this.Controls.Add(this.CreateDevice);
            this.Name = "Form1";
            this.Text = "VSPE API Sample";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.OnClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button CreateDevice;
        private System.Windows.Forms.Button Info;
        private System.Windows.Forms.Label label1;
    }
}

