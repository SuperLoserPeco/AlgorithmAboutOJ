#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        sort(nums.begin(), nums.end());
        int cur = 1;
        if(nums.size() == 0) return ret;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                cur++;
            }
            else {
                if(cur * 3 > nums.size()) {
                    ret.push_back(nums[i - 1]);
                }
                cur = 1;
            }
        }
        if(cur * 3 > nums.size()) ret.push_back(nums[nums.size() - 1]);
        return ret;
    }
};