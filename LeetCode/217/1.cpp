#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>

#include <sstream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1]) return true;
        }
        return false;      
    }
};