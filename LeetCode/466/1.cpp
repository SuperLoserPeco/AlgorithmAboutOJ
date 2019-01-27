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

//https://www.cnblogs.com/heisenberg-/p/6663587.html
// 直接给出DP方程

// dp[i][k]=dp[i][k-1]+dp[(i+dp[i][k-1])%len1][k-1];

// dp[i][k]表示从字符串s1的第i位开始匹配2^k个s2串需要的长度 

// 最后通过一个循环 累积最多可以匹配多少个s2串 除以n2下取整就是答案

 

// 用倍增加速后 总的复杂度nlogn 而本题的n非常小 轻松AC 

// 体会到倍增的魅力了吧。

const int maxp = 30;
const int maxn = 101;
const int INF = 1e+9;
LL dp[maxn][maxp];

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        memset(dp, 0, sizeof(dp));
        int len1 = s1.length();
        int len2 = s2.length();
        int l1 = 0, l2 = 0;
        for(int i = 0; i < len1; i++)
        {
            l1 = i; l2 = 0;
            while(l2 < len2)
            {
                while(l1 < n1 * len1 && 
                        s1[l1 % len1] != s2[l2])
                {
                    l1++;
                }
                l1++; l2++;
            }
            dp[i][0] = l1 - i;
        }
        for(int k = 1; k < maxp; k++)
        {
            for(int i = 0; i < len1; i++)
            {
                dp[i][k] = dp[i][k - 1] + 
                    dp[(i + dp[i][k - 1]) % len1][k - 1];
            }
        }
        LL ans = 0;
        int begin = 0;
        for(int k = maxp - 1; k >= 0; k--)
        {
            while((begin + dp[(begin % len1)][k]) <= n1 * len1)
            {
                ans += (1 << k);
                begin += dp[(begin % len1)][k];
            }
        }
        return ans / n2;
    }
};