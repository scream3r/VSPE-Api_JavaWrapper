using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using VSPELib;

namespace VSPE_API_Test
{
    public partial class Form1 : Form
    {
        private VSPEApiClass vspe;

        public Form1()
        {
            InitializeComponent();

            vspe = new VSPEApiClass();
            int result;
            string activationKey = ""; // <-----  PUT ACTIVATION KEY HERE

            // display VSPE API info
            label1.Text = vspe.vspe_getVersionInformation();

            // activate VSPE API
            result = vspe.vspe_activate(activationKey);

            // initialize API
            result = vspe.vspe_initialize();
        }

        private void CreateDevice_Click(object sender, EventArgs e)
        {
            int result;

            // Stop emulation
            result = vspe.vspe_stopEmulation();

            // Deatroy all devices
            result = vspe.vspe_destroyAllDevices();

            // Add Connector (COM9, no baud rate emulation)
            result = vspe.vspe_createDevice("Connector", "9;0");

            // Start emulation
            result = vspe.vspe_startEmulation();
        }

        private void OnClosing(object sender, FormClosingEventArgs e)
        {
            // Stop emulatio
            vspe.vspe_stopEmulation();

            // Release VSPE
            vspe.vspe_release();
        }

        private void Info_Click(object sender, EventArgs e)
        {
            // get devices count
            int count = vspe.vspe_getDevicesCount();
            string result = "Devices count: " + count.ToString() + "\n";

            // enumerate devices
            for (int i = 0; i < count; ++i)
            {
                // get device ID
                int deviceId = vspe.vspe_getDeviceIdByIdx(i);
                string name, initString;
                int ok, used;
                vspe.vspe_getDeviceInfo(deviceId, out name, out initString, out ok, out used);

                result += name + " ("+initString + ") OK=" + ok.ToString() + "\n";
            }

            MessageBox.Show(result);
        }
    }
}
