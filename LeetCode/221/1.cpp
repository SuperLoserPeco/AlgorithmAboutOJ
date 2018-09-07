#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;

        int szX = matrix.size();
        int szY = matrix[0].size();
        if(szY == 0) return 0;

        int*** dp = new int**[szX];
        for(int i = 0; i < szX; i++) {
            dp[i] = new int*[szY];
            for(int j = 0; j < szY; j++)
                dp[i][j] = new int[2];
        }

        int **dp2 = new int*[szX];
        for(int i = 0; i < szX; i++)
            dp2[i] = new int[szY];

        int **dp3 = new int*[szX];
        for(int i = 0; i < szX; i++)
            dp3[i] = new int[szY];


        for(int i = szX - 1; i >= 0; i--) {
            for(int j = szY - 1; j >= 0; j--) {
                int cur = (matrix[i][j] - '0');
                if(i == szX - 1) {
                    dp[i][j][0] =  cur;
                }
                else {
                    if(cur == 0) dp[i][j][0] =  0;
                    else dp[i][j][0] = dp[i + 1][j][0] + 1;
                }

                if(j == szY - 1) {
                    dp[i][j][1] = cur;
                }
                else {
                    if(cur == 0) dp[i][j][1] = 0;
                    else dp[i][j][1] = dp[i][j + 1][1] + 1;
                }
            }
        }

        int ret = 0;
        for(int i = szX - 1; i >= 0; i--) {
            for(int j = szY - 1; j >= 0; j--) {
                int cur = (matrix[i][j] - '0');
                if(i == szX - 1 || j == szY - 1) {
                    dp2[i][j] = cur;
                    dp3[i][j] = cur; 
                }
                else {
                    if(cur == 0) {
                        dp2[i][j] = 0;
                        dp3[i][j] = cur;
                    }
                    else {
                        dp3[i][j] = min(min(dp[i][j][0], dp[i][j][1]), dp3[i + 1][j + 1] + 1);
                        dp2[i][j] = dp3[i][j] * dp3[i][j];
                    }
                }
                ret = max(ret, dp2[i][j]);
            }
        } 
        return ret;
    }
};