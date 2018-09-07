#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>

#include <sstream>
using namespace std;

//sb le
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int locate = 1;
        int mx = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) locate++;
            else locate = 1;
            mx = max(mx, locate);
        }
        return mx - 1 >= k;
    }
};