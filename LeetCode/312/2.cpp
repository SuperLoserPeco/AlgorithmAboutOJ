#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <set>

#include <algorithm>
using namespace std;

typedef long long LL;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size() + 2;
        int** dp = new int*[sz];
        for(int i = 0; i < sz; i++)
        {
            dp[i] = new int[sz];
            for(int j = 0; j < sz; j++)
            {
                dp[i][j] = 0;
            }
        }
        int* newnums = new int[sz];
        for(int i = 0; i < sz - 2; i++)
        {
            newnums[i + 1] = nums[i];
        }
        newnums[0] = newnums[sz - 1] = 1;
        for(int k = 2; k < sz; k++)
        {
            for(int l = 0; l + k < sz; l++)
            {
                int h = l + k;
                for(int m = l + 1; m < h; m++)
                {
                    dp[l][h] = max(dp[l][h], newnums[l] * newnums[m] * newnums[h] + dp[l][m] + dp[m][h]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};