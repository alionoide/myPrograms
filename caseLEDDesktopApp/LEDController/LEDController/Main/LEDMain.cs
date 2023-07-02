using LEDController.Main.View;
using LEDController.Main.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace LEDController.Main
{
    public class LEDMain
    {
        public MainView view;

        public LEDMain() 
        {
            setupView();
            attachLogic();
        }

        private void setupView()
        {
            view = new MainView();
            view.DataContext = new MainVM();
        }

        private void attachLogic()
        {

        }
    }
}
