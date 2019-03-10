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
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[1][0] = 0;
        dp[1][1] = 0; 

        return dp[n];
    }
};