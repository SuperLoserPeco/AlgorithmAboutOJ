using System;
using System.Collections.Generic;
namespace myApp.cs228
{
    public class Solution {
        public IList<string> SummaryRanges(int[] nums) {
            List<string> ret = new List<string>();
            if(nums.Length == 0) return ret;
            int pre = nums[0];

            for(int i = 1; i < nums.Length; i++) {
                if(nums[i] == nums[i - 1] + 1) {

                }
                else {
                    if(pre == nums[i - 1]) {
                        ret.Add("" + pre);
                    }
                    else {
                        ret.Add("" + pre + "->" + nums[i - 1]);
                    }
                    pre = nums[i];
                }
            }
            if(pre == nums[nums.Length - 1]) {
                ret.Add("" + pre);
            }
            else {
                ret.Add("" + pre + "->" + nums[nums.Length - 1]);
            }

            return ret;
        }
    }
}