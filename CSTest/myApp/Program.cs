using System;
using System.Collections.Generic;

using myApp.dspt.zsms;
namespace myApp
{
    public class SomeType
    {
        public int ss {get; set;} = 2;
        public bool ssa {get; set;} = true;
        public string Test { get; set; } = "aa";
    }
    class Program
    {
        public static void Test(SomeType aa)
        {
            aa.Test = "bb";
        }
        static void Main(string[] args)
        {   
            SomeType test = new SomeType();
            Console.WriteLine($"xxxx {test.ss}");
            Console.WriteLine($"xxxx {test.ssa}");
            SomeType tes = new SomeType();
            Console.WriteLine(tes.Test);
            Test(tes);
            Console.WriteLine(tes.Test);
            // TimeSpan test = DateTime.Now.ToUniversalTime() - new DateTime(1970, 1, 1);
            // Console.WriteLine(Convert.ToInt64(test.TotalSeconds));
            // test = DateTime.Now - new DateTime(1970, 1, 1);
            // long a = 5;
            // long b = 2;
            // Console.WriteLine((int)(a / b));
            // // Progress.Run();
            // List<Test> lst = new List<Test>();

            // bbb c = new bbb();
            // if(c.ccc == null){
            //     Console.WriteLine("haha1");
            // }
            // else {
            //     Console.WriteLine("haha2");
            // }
            
            // string test2 = "我hl吗";
            // for(int i = 0; i < test2.Length; i++) {
            //     char cc = test2[i];
            //     Console.WriteLine(cc);
            //     Console.WriteLine("");
            //     byte[] bts = BitConverter.GetBytes (cc);
            //     for(int j = 0; j < bts.Length; j++) {
            //         Console.WriteLine(bts[j]);
            //         if(bts[j] == 0) {
            //             Console.WriteLine("Blank");
            //         }
            //     }
            //     Console.WriteLine("");
            //     Console.WriteLine(bts.Length);
            // }
            // Guid test1111 = Guid.NewGuid();
            // Console.WriteLine(test1111.ToString().Length);
            // Console.WriteLine()

            char cccc = (char)0;
            if(cccc == 0)
            {
                Console.WriteLine("haha");
            }

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
