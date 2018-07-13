using System;

using myApp.Algorithms;
namespace myApp
{
    class Program
    {
        static Manacher p;
        static void Main(string[] args)
        {
            p = new Manacher();
            string s = "ccaacabacb";
            int sz = s.Length;
            p.manacherInit(s.ToCharArray());
            // for(int i = 0; i < sz; i++) {
            //     Console.WriteLine("i = " + i);
            //     Console.WriteLine("odd = " + p.stringLocateToLength(i + 1, true));
            //     Console.WriteLine("no = " + p.stringLocateToLength(i + 1, false));
            // }
            p.output();

            // Student gs = new Student();
            // gs.sleep();
            // Console.WriteLine("Hello World!");
        }
    }
}
