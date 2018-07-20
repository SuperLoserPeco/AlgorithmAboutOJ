#include <vector>
#include <string>
using namespace std;

//Algorithm
//O(n^3)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int x = matrix.size();
        if(x == 0) return 0;
        int y = matrix[0].size();
        // int** dp = new int[x][y];

        int** dp = new int*[x];
        for(int i = 0; i < x; i++)
            dp[i] = new int[y];

        for(int i = 0; i < x; i++) {
            for(int j = y - 1; j >= 0; j--) {
                if(j == y - 1) dp[i][j] = (matrix[i][j] - '0');
                else {
                    if(matrix[i][j] == '0') {
                        dp[i][j] = 0;
                    }
                    else {
                        dp[i][j] = dp[i][j + 1] + (matrix[i][j] - '0');
                    }
                }
            }
        }

// [["1","0","1","0","0"],
// ["1","0","1","1","1"],
// ["1","1","1","1","1"],
// ["1","0","0","1","0"]]

        int ret = 0;
        for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++) {
            int top = 0; int botton = x - 1;
            for(int k = i - 1; k >= 0; k--) {
                if(dp[k][j] < dp[i][j]) {
                    top = k + 1;
                    break;
                }
            }
            for(int k = i + 1; k < x; k++) {
                if(dp[k][j] < dp[i][j]) {
                    botton = k - 1;
                    break;
                }
            }
            ret = max(ret, (botton - top + 1) * dp[i][j]);
            if((botton - top + 1) * dp[i][j] == 12) {
                // cout << botton << "---" << top << endl;
                // cout << i << "---" << j << endl;
            }
        }
        return ret;
    }
};