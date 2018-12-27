#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;



// dp[i]表示前i个数的不同子序列个数，对于a[i]
// 1.在之前没出现过，dp[i]=dp[i-1]+dp[i-1]+1
// 2.在之前出现过，最近的位置为x，dp[i]=dp[i-1]+dp[i-1]-dp[x-1]

const int maxn = 2020;
const int mod = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string S) {
        int dp[maxn];
        int locate[maxn];
        memset(dp, 0, sizeof(dp));
        memset(locate, 0, sizeof(locate));
        int n = S.size();
        for(int i = 1; i <= n; i++) {
            int last = locate[S[i - 1] - '0']; 
            if(last != 0)
            {
                dp[i] = dp[i - 1] * 2 - dp[last - 1];
            }
            else{
                dp[i] = dp[i - 1] * 2 + 1;
            }

            if(dp[i] < 0) dp[i] += mod;
            dp[i] %= mod;
            
            locate[S[i - 1] - '0'] = i;
        }
        return dp[n];
    }
};