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
    int lastStoneWeightII(vector<int>& stones) {
        int sz = stones.size();
        int* dp = new int[1 << sz];
        dp[0] = 0;
        int INF = 1200;
        for(int i = 1; i < (1 << sz); i++)
        {
            dp[i] = INF;
            for(int j = 0; j < sz; j++)
            {
                if(dp[i] == 0)
                {
                    break;
                }
                if(i & (1 << j))
                {
                    dp[i] = min(dp[i], abs(stones[j] - dp[i - (1 << j)]));
                }
            }
        }
        return dp[(1 << sz) - 1];
    }
};

int main() {
    
    return 0;
}