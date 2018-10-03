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
            TimeSpan test = DateTime.Now.ToUniversalTime() - new DateTime(1970, 1, 1);
            Console.WriteLine(Convert.ToInt64(test.TotalSeconds));
            test = DateTime.Now - new DateTime(1970, 1, 1);
            long a = 5;
            long b = 2;
            Console.WriteLine((int)(a / b));
            // Progress.Run();
            List<Test> lst = new List<Test>();
            
            // Console.WriteLine(default() == null);
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
