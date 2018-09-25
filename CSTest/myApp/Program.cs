using System;
using System.Collections.Generic;

using myApp.dspt.zsms;
namespace myApp
{
    class Test {
        public int a;
        public int b;
    }
    class Program
    {
        static void Main(string[] args)
        {
            // Progress.Run();
            List<Test> lst = new List<Test>();
            
            Console.WriteLine(default() == null);
            // Console.WriteLine("-----");
            // for(int i = 0; i < 10; i++) {
            //     Test tt = new Test();
                
            //     tt.a = i + 1;
            //     tt.b = i % 3 == 1 ? 22 : i;
            //     Console.WriteLine("i = " + i + " a = " + tt.a + " b = " + tt.b);
            //     lst.Add(tt);
            // }
            // Console.WriteLine("-----");
            // for(int i = 0; i < lst.Count; i++) {
            //     Test tt = lst[i];
            //     Console.WriteLine("i = " + i + " a = " + tt.a + " b = " + tt.b);
            //     if(tt.b == 22) {
            //         lst.Remove(tt);
            //         i--;
            //     }
            // }
            // Console.WriteLine("-----");
            // for(int i = 0; i < lst.Count; i++) {
            //     Test tt = lst[i];
            //     Console.WriteLine("i = " + i + " a = " + tt.a + " b = " + tt.b);
            // }
        }
    }
}
