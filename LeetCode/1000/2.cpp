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
    int k;
    int n;
    int INF;
    vector<vector<vector<int>>> dp;
    vector<vector<vector<bool>>> vis;
    vector<int> sum;
    int dfs(int l, int r, int m)
    {
        if(vis[l][r][m])
        {
            return dp[l][r][m];
        }

        vis[l][r][m] = true;
        if(l == r)
        {
            if(m == 1)
            {
                dp[l][r][m] = 0;
            }
            return dp[l][r][m];
        }

        if(m == 1)
        {
            dp[l][r][m] = dfs(l, r, k) + sum[r + 1] - sum[l];
            return dp[l][r][m];
        }

        for(int i = l; i < r; i++)
        {
            dp[l][r][m] = min(dp[l][r][m], dfs(l, i, 1) + dfs(i + 1, r, m - 1));
        }
        return dp[l][r][m];
    }

    int mergeStones(vector<int>& stones, int K) {
        INF = 0xFFFF;
        k = K;
        n = stones.size();
        if((n - 1) % (k - 1) != 0)
        {
            return -1;
        }
        dp.resize(n, vector<vector<int>>(n, vector<int>(K + 1)));
        vis.resize(n, vector<vector<bool>>(n, vector<bool>(K + 1)));
        sum.resize(n + 1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int l = 1; l <= k; l++)
                {
                    dp[i][j][l] = INF;
                    vis[i][j][l] = false;
                }
            }
        }
        sum[0] = 0;
        for(int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + stones[i];
        }

        int ret = dfs(0, n - 1, 1);
        return ret < INF ? ret : -1;
    }
};

int main()
{
    Solution s;
    vector<int> param = {1, 2, 3};
    int result = s.mergeStones(param, 3);
    cout << result << endl;
    return 0;
}