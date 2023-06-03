using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace LEDController.Main.ApplicationLogic
{
    public class MainInteractor
    {
        SerialPort serialPort = new SerialPort("COM11", 115200, Parity.None, 8, StopBits.One);


        public MainInteractor() 
        {
            TestFN();
        }



        public void TestFN()
        {
            serialPort.Open();

            serialPort.Write("Testing");

            serialPort.Close();
        }
    }
}
