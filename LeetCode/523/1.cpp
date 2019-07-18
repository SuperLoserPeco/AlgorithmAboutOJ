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
        int l = 0, r = 0;
        int sz = nums.size();
        int current = 0;
        while(l < sz && r < sz)
        {
            current += nums[r];
            if(r - l > 1)
            {
                if(k == 0)
                {
                    if(current == 0)
                    {
                        return true;
                    }
                }
                else{
                    if(current % k == 0)
                    {
                        return true;
                    }
                }
            }

            if(current > k)
            {
                current -= nums[l];
                if(l == r)
                {
                    l++; r++;
                }
                else{
                    l++;
                }
            }
            else{
                r++;
            }
            if(r - l > 1)
            {
                if(k == 0)
                {
                    if(current == 0)
                    {
                        return true;
                    }
                }
                else{
                    if(current % k == 0)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}