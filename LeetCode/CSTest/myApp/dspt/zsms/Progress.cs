using System;

namespace myApp.dspt.zsms
{
    public class Progress
    {
        public static void Run() {
            Person xc = new Person("noob");

            TShirts ts = new TShirts();
            BigTrouser bt = new BigTrouser();
            ts.Decorate(xc);
            bt.Decorate(ts);

            bt.Show();
        }
    }
}