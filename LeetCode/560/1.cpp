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

typedef long long LL;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;

        int ret = 0;
        mp[0] = 1;
        int current = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            current += nums[i];
            ret += mp[current - k];
            mp[current]++;
        }
        return ret;
    }
};

int main() {
    
    return 0;
}