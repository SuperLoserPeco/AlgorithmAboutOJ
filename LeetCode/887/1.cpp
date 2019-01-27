#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;

// O(K * N^2)
// 首先，这个题比较绕。需要求一个最优决策使得步数最小，但是实际的步数是随着真实结果变化而变化的。
// 于是，为了保证在我们假设的步数内一定能够解完，我们可以假设每次决策都会得到最坏结果。

// dp[n][k] 表示用k个鸡蛋测n层最少需要多少步。
// 我们可以枚举第一次在第i层扔鸡蛋，会得到两种结果:

//     鸡蛋坏掉: 我们接下来需要面对的情形是: 用 k-1 个鸡蛋来测量 i-1 层，所以最少需要 dp[i-1][k-1] 步。
//     鸡蛋没坏: 我们接下来要面对的情形是: 用 k 个鸡蛋来测量 n-i 层，所以最少需要 dp[n-i][k] 步。
//     因为我们总会面对最坏情况，所以，在第i层扔，会用 max(dp[i-1][k-1], dp[n-i][k]) + 1 步。

// 所以我们的递推式如下:
// dp[n][k] = min{ max(dp[i-1][k-1], dp[n-i][k]) + 1 } (1 <= i <= n)

const int maxk = 140;
const int maxn = 10010;

class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[maxn][maxk];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= N; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int n = 1; n <= N; n++)
        {
            for(int k = 1; k <= K; k++)
            {
                dp[n][k] = n;
                if(k > 1)
                {
                    for(int i = 2; i < n; i++)
                    {
                        int val = max(dp[i - 1][k - 1], dp[n - i][k]) + 1;
                        dp[n][k] = min(dp[n][k], val);
                    }
                }
            }
        }

        return dp[N][K];
    }
};