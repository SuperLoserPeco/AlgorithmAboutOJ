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
//声明多维动态数组 报错
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(2)));
        // int*** dp = new int**[n1 + 1];
        // for(int i = 0; i < n1 + 1; i++)
        // {
        //     dp[i] = new int*[n2 + 1];
        //     for(int j = 0; j < n2 + 1; j++)
        //     {
        //         dp[i][j] = new int[2];
        //     }
        // }
        // memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n1 + 1; i++)
        {
            for(int j = 0; j < n2 + 1; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    dp[i][j][k] = 0;
                }
            }
        }
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                if(i == 0)
                {
                    dp[i][j][1] = dp[i][j - 1][1];
                    int last = dp[i][j - 1][1];
                    if(s2[j - 1] == s3[last])
                    {
                        dp[i][j][1] = dp[i][j][1] + 1;
                    }
                }
                else if(j == 0)
                {
                    dp[i][j][0] = dp[i - 1][j][0];
                    int last = dp[i - 1][j][0];
                    if(i == 1)
                    {
                        cout << last << "---" << endl;
                    }
                    if(s1[i - 1] == s3[last])
                    {
                        dp[i][j][0] = dp[i][j][0] + 1;
                    }
                }
                else{
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                    dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]);
                    int last = dp[i][j][0];
                    if(s1[i - 1] == s3[last])
                    {
                        dp[i][j][0] = max(dp[i][j][0], dp[i][j][0] + 1);
                    }
                    last = dp[i][j][1];
                    if(s2[j - 1] == s3[last])
                    {
                        dp[i][j][1] = max(dp[i][j][1], dp[i][j][1] + 1);
                    }
                }
            }
        }
        return (dp[n1][n2][0] == n3 || dp[n1][n2][1] == n3) && (n1 + n2 == n3) ;
    }
};