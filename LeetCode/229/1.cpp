#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                cur++;
            }
            else {
                if(cur * 3 >= nums)
                cur = 1;
            }
        }
    }
};