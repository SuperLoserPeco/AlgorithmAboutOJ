using System;

namespace myApp.cs198
{
    public class Solution {
        public int Rob(int[] nums) {
            int sz = nums.Length;
            int[] dp = new int[sz];
            int ret = 0;
            for(int i = 0; i < sz; i++) {
                dp[i] = nums[i];
                ret = Math.Max(ret, dp[i]);
            }
            for(int i = 2; i < sz; i++) {
                dp[i] = dp[i - 2] + nums[i];
                if(i >= 3) {
                    dp[i] = Math.Max(dp[i], dp[i - 3] + nums[i]);
                }
                ret = Math.Max(ret, dp[i]);
            }
            return ret;
        }
    }
}