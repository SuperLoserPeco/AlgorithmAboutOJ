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
    int minStickers(vector<string>& stickers, string target) {
        int n = target.length(), m = 1 << n;
        int* dp = new int[m];
        for(int i = 0; i < m; i++)
        {
            dp[i] = INT32_MAX;
        }

        dp[0] = 0;

        for(int i = 0; i < m; i++)
        {
            if(dp[i] == INT32_MAX)
            {
                continue;
            }
            int count = stickers.size();
            for(int j = 0; j < count; j++)
            {
                int mask = i;
                for(int k = 0; k < stickers[j].length(); k++)
                {
                    for(int l = 0; l < n; l++)
                    {
                        if((mask >> l) & 1 == 1) {
                            continue;
                        }
                        if(target[l] == stickers[j][k])
                        {
                            mask |= (1 << l);
                            break;
                        }
                    }
                }
                dp[mask] = min(dp[mask], dp[i] + 1); 
            }
        }
        return dp[m - 1] == INT32_MAX ? -1 : dp[m - 1];
    }
};