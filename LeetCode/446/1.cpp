
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty()) return 0;
        vector<unordered_map<int, int>> dp(A.size());
        int ans = 0;

        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((long)A[i] - (long)A[j] > INT_MAX || 
                    (long)A[i] - (long)A[j] < INT_MIN)
                    {
                        continue;
                    }
                int delta = A[i] - A[j];
                dp[i][delta] += 1;
                if(dp[j].find(delta) != dp[j].end())
                {
                    dp[i][delta] += dp[j][delta];
                    ans += dp[j][delta];
                }
            }
        }
        return ans;
    }
};