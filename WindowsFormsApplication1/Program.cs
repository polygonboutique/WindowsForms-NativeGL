using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using TheWrapper;

namespace WindowsFormsApplication1
{
    static class Program
    {

        static public LibWrapper lw;

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            var form = new Form1();

            unsafe
            {
                void* hwndPointer = form.Handle.ToPointer();

                Console.WriteLine("- - - - Console - - - - -");
                Console.WriteLine((IntPtr)hwndPointer);

                lw = new LibWrapper();
                lw.SetHWND(hwndPointer);
                lw.Init();
            }

            Application.Run(form);
        }
    }
}
