#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

class Solution {
public:
    map<int, int> mp;
    map<int, bool> vis;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        mp.clear();
        vis.clear();

        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            if(!vis[nums[i]]) {
                vis[nums[i]] = true;
                mp[nums[i]] = i;
            }
            else {
                if(i - mp[nums[i]] <= k)
                return true; 
                else
                    mp[nums[i]] = i;
            }
        }
        return false;
    }
};