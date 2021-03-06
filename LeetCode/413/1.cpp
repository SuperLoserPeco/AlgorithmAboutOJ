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
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        int* dp = new int[sz];
        for(int i = 0; i < sz; i++)
        {
            dp[i] = 0;
        }
        int ans = 0;
        for(int i = 2; i < sz; i++)
        {
            if((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]))
            {
                if(dp[i - 1] != 0)
                {
                    dp[i] = dp[i - 1] + 1;
                }
                else{
                    dp[i] = 1;
                }
                ans += dp[i];
            }
            else{
                dp[i] = 0;
            }
        }
        return ans;
    }
};