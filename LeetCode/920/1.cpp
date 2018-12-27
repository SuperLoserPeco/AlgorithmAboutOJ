#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 110;
const int mod = 1e9 + 7;
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        LL dp[maxn];
        dp[0] = 1;
        for(int i = 1; i <= K + 1; i++)
        {
            dp[i] = (dp[i - 1] * (N - i + 1)) % mod;
        }
        int pwd = 1;
        for(int i = 1; i <= K; i++)
        {
            pwd = (pwd * (N - i)) % mod;
        }
        for(int i = K + 1 + 1; i <= L; i++)
        {
            dp[i] = ((dp[i - (K + 1)] % mod) * (pwd % mod)) % mod;
        }
        return dp[L] % mod;
    }
};