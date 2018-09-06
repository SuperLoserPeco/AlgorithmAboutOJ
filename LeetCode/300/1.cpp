#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        int* dp = new int[nums.size()];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++) {
            int locate = find(temp.begin(), temp.end(), nums[i]) - temp.begin();
            dp[locate] = 1;
            for(int j = 0; j < locate; j++) {
                dp[locate] = max(dp[locate], dp[j] + 1);
            }
            ans = max(ans, dp[locate]);
        }
        return ans;
    }
};