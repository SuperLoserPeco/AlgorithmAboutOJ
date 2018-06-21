#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int dp[100000];
    int integerReplacement(int n) {
        dp[1] = 0; dp[2] = 1;
        int fi = n;
        if(n % 2) fi = n + 1;
        for(int i = 3; i <= fi; i += 2) {
            dp[i + 1] = dp[(i + 1) / 2] + 1;
            dp[i] = min(dp[i - 1], dp[i + 1]) + 1;
        }
        return dp[n];
    }
};