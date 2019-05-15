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
//https://blog.csdn.net/hh66__66hh/article/details/88090599
class Solution {
public:
    int dp(int l, int r, int m, int k,
            vector<vector<vector<int>>> ans, 
            vector<vector<vector<int>>> flag,
            vector<int> sum )
            {
                
            }
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n - 1) % (k - 1) != 0)
        {
            return -1;
        }
        vector<int> sum(n + 1);
        sum[0] = 0;
        for(int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + stones[i];
        }
        vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(K + 1)));
        vector<vector<vector<int>>> flag(n, vector<vector<int>>(n, vector<int>(K + 1)));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int a = 1; a <= K; a++)
                {
                    ans[i][j][a] = 0xFFFF;
                    flag[i][j][a] = 0;
                }
            }
        }
    }
};