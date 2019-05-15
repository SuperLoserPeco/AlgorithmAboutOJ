namespace myApp.cs260
{
    public class Solution
    {
        public int[] SingleNumber(int[] nums) {
            int len = nums.Length;
            
            int xor = 0;
            for(int i = 0; i < len; i++)
                xor = xor ^ nums[i];

            int flag = 0x01;
            while(true) {
                if((flag & xor) > 0) break;
                flag = flag << 1;
            }

            int[] ret = new int[2];
            for(int i = 0; i < len; i++) {
                if((nums[i] & flag) > 0) ret[0] = ret[0] ^ nums[i];
                else ret[1] = ret[1] ^ nums[i];
            }

            return ret;
        }
    }
}