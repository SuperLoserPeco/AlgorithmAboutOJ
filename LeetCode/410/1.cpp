#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>

#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();

        int** dp = new int*[sz + 1];
        for(int i = 0; i < sz + 1; i++) {
            dp[i] = new int[m + 1];
        }

        memset(dp, -1, sizeof(dp));
    }
};