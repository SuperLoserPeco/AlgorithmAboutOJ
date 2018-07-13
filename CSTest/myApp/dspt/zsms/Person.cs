using System;

namespace myApp.dspt.zsms
{
    public class Person
    {
        private string name;

        public Person() {

        }
        public Person(string name) {
            this.name = name;
        }

        public virtual void Show() {
            Console.WriteLine(" zhuangbande {0}", name);
        }

        public void WearTshirts() {
            
        }
    }
}