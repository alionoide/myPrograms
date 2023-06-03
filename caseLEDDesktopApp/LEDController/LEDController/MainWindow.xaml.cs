using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LEDController
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            SerialPort.GetPortNames().ToList().ForEach(portName => comList.Items.Add(portName));
        }




        private void test_Click(object sender, RoutedEventArgs e)
        {
            SerialPort serialPort = new SerialPort(comList.SelectedItem as string, 115200, Parity.None, 8, StopBits.One);

            serialPort.Open();

            serialPort.Write("Testing");

            serialPort.Close();
        }

        private void getList_Click(object sender, RoutedEventArgs e)
        {
            SerialPort.GetPortNames().ToList().ForEach(portName => comList.Items.Add(portName));
        }
    }
}
