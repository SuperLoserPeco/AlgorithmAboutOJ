#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        int ret = 0;
        if(!sz) return 0;
        int szY = triangle[sz - 1].size();
        int dp[2][szY];
        int now = 0;

        for(int i = 0; i < sz; i++) {
            int cursz = triangle[i].size();
            for(int j = 0; j < cursz; j++) {
                if(i == 0) dp[now][j] = triangle[i][j];
                else {
                    if(j == 0) 
                        dp[now][j] = dp[1 - now][j] + triangle[i][j];
                    else if(j == cursz - 1)
                        dp[now][j] = dp[1 - now][j - 1] + triangle[i][j];
                    else
                        dp[now][j] = min(dp[1 - now][j], dp[1 - now][j - 1]) + triangle[i][j];
                }
            }
            ret = dp[now][0];
            for(int i = 1; i < cursz; i++)
                ret = min(ret, dp[now][i]);
            now = 1 - now;
        }
        return ret;
    }
};