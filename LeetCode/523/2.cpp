#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        for(int i = 1; i < sz; i++)
        {
            if(nums[i] == 0 && nums[i - 1] == 0)
            {
                return true;
            }
        }
        if(k == 0)
        {
            return false;
        }

        for(int i = 0; i < sz; i++)
        {
            int sum = nums[i];
            for(int j = i + 1; j < sz; j++)
            {
                sum += nums[j];
                if(sum%k == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}