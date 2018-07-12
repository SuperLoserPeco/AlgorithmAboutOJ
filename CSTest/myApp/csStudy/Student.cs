using System;

namespace myApp.csStudy
{
    public class Student : People
    {
        public override void talk() {
            // Console.WriteLine("s talk");
        }

        public virtual void sleep() {
            Console.WriteLine("s sleep");
        }
    }
}