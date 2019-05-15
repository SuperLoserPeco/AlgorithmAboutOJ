using System;
namespace myApp.cs128
{
    //其实并没有通过
public class Solution {
    public int LongestConsecutive(int[] nums) {
        if(nums.Length <= 1) return nums.Length;
        Array.Sort(nums);
        int ret = 1;
        int cur = 1;
        for(int i = 1; i < nums.Length; i++) {
            Console.WriteLine(nums[i]);
            if(nums[i] == nums[i - 1] + 1) cur++;
            else if(nums[i] == nums[i - 1]) continue;
            else cur = 1;
            ret = ret > cur ? ret : cur;
        }
        return ret;
    }
}
}