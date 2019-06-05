#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.length();
        int sz2 = word2.length();
        if(sz1 == 0 || sz2 == 0)
        {
            return sz1 + sz2;
        }
        vector<vector<int>> dp(sz1, vector<int>(sz2));
        for(int i = 0; i < sz1; i++)
        {
            for(int j = 0; j < sz2; j++)
            {
                if(!i && !j)
                {
                    dp[i][j] = word1[i] == word2[j] ? 1 : 0;
                }
                else{
                    dp[i][j] = 0;
                    if(i && j)
                    {
                        dp[i][j] = max(dp[i][j], (word1[i] == word2[j] ? 1 : 0) + dp[i - 1][j - 1]);
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                    }
                    else if(i)
                    {
                        dp[i][j] = max(dp[i][j], (word1[i] == word2[j] ? 1 : 0));
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    }
                    else if(j)
                    {
                        dp[i][j] = max(dp[i][j], (word1[i] == word2[j] ? 1 : 0));
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                    }
                }
            }
        }
        int commonSz = dp[sz1 - 1][sz2 - 1];
        return sz1 + sz2 - commonSz * 2;
    }
};

int main() {
    
    return 0;
}