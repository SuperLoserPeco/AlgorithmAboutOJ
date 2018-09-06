#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1;
        int sz = nums.size();
        int minLen = 0;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            r++;
            cur += nums[i];
            if(cur >= s) {
                do {
                    minLen = (minLen == 0) ? (r - l + 1) : min(minLen, (r - l + 1));
                    cur -= nums[l];
                    l++;
                } while(cur >= s);
            }

        }
        return minLen;
    }
};