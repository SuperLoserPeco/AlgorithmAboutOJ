//脑子很不清醒啊

namespace myApp.cs335
{
    public class Solution
    {
        int[] dx = {0, -1, 0, 1};
        int[] dy = {1, 0, -1, 0};
        public bool IsSelfCrossing(int[] x) {
            if(x.Length < 4) return false;
            int nx = 0, ny = 0;

            int[] border = new int[4];

            border[0] = 0;
            for(int i = 0; i < 3; i++) {
                nx = nx + dx[i] * x[i];
                ny = ny + dy[i] * x[i];

                border[i + 1] = i % 2 == 1 ? nx : ny;
            }
            for(int i = 3; i < x.Length; i++) {
                nx = nx + dx[i] * x[i];
                ny = ny + dy[i] * x[i];

                int nborder = i % 2 == 1 ? nx : ny;

                if(i % 4 == 3 && nborder >= border[])

                border[i % 4] = nborder;
            }


            return false;            
        }
    }
}