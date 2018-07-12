namespace myApp.csStudy
{
    public class GoodStudent : Student
    {
        //没有override Student gs = new GoodStudent(); gs.talk();
        //s talk

        //有override Student gs = new GoodStudent(); gs.talk();
        //goods talk
        public override void talk() {
            // System.Console.WriteLine("goods talk");
        }

        
        public override void sleep() {
            System.Console.WriteLine("goods sleep");
        }
    }
}