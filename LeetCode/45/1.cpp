#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int* dp = new int[sz];

        dp[sz - 1] = 0;

        for(int i = sz - 2; i >= 0; i--) {
            int range = sz - 1 - i;
            dp[i] = range;
            for(int k = 1; k <= min(nums[i], range); k++) {
                dp[i] = min(dp[i], dp[i + k] + 1);
            }
        }
        return dp[0];
    }
};