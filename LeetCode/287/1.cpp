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
    int findDuplicate(vector<int>& nums) {
        int sz = nums.size();
        int l = 0, r = sz;
        while(l < r) {
            int md = (l + r) / 2;
            int num = 0;
            for(int i = 0; i < sz; i++) {
                if(nums[i] <= md) num++;
            }
            if(num > md) r = md;
            else l = md + 1;
        }
        return l;
    }
};