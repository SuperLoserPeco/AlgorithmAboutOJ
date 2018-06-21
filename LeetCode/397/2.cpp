#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<long long, int> dp;
    
    int dfs(long long n) {
        if(n == 1) return 0;
        else if(n == 2) return 1;

        if(dp[n] != 0) return dp[n];

        if(n % 2) dp[n] = min(dfs(n - 1), dfs(n + 1)) + 1;
        else dp[n] = dfs(n / 2) + 1;
        return dp[n];
    }

    int integerReplacement(int n) {
        return dfs((long long)n);
    }
};