#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
        {
            return 0;
        }
        else if(sz == 2)
        {
            return nums[0] > nums[1] ? 0 : 1;
        }


        for(int i = 1; i < sz - 1; i++)
        {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                return i;
            }
        }
        if(nums[sz - 1] > nums[sz - 2])
        {
            return sz - 1;
        }
        if(nums[0] > nums[1])
        {
            return 0; 
        }

        return -1;
    }
};

int main() {
    
    return 0;
}