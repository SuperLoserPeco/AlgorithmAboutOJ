#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int szX = dungeon.size();
        int szY = dungeon[0].size();

        vector<vector<int>> dp, dp2;
        dp.resize(szX);
        dp2.resize(szX);
        for(int i = 0; i < szX; i++) {
        	dp[i].resize(szY);
        	dp2[i].resize(szY);
        }
        	dp[0][0] = dungeon[0][0];
        	dp2[0][0] = dungeon[0][0];
        for(int i = 1; i < szX; i++) {
        	dp[i][0] = dp[i - 1][0] + dungeon[i][0];
        	dp2[i][0] = min(dp2[i - 1][0], dp[i][0]);
                cout << i << "--- " << 0 << "--- " << dp[i][0] << endl;
                cout << i << "--- " << 0 << "--- " << dp2[i][0] << endl;
        }
        for(int i = 1; i < szY; i++) {
        	dp[0][i] = dp[0][i - 1] + dungeon[0][i];
        	dp2[0][i] = min(dp2[0][i - 1], dp[0][i]);
                cout <<0 << "--- " << i << "--- " << dp[0][i] << endl;
                cout <<0 << "--- " << i << "--- " << dp2[0][i] << endl;
        }

        for(int i = 1; i < szX; i++)
        	for(int j = 1; j < szY; j++) {
        		if(dp2[i - 1][j] > dp2[i][j - 1]) {
					dp[i][j] = dp[i - 1][j] + dungeon[i][j];
					dp2[i][j] = min(dp[i][j], dp2[i - 1][j]);
        		}
        		else {
        			dp[i][j] = dp[i][j - 1] + dungeon[i][j];
					dp2[i][j] = min(dp[i][j], dp2[i][j - 1]);
        		}
                cout << i << "---1" << j << "--- " << dp[i][j] << endl;
                cout << i << "---2" << j << "--- " << dp2[i][j] << endl;
        	}
        return dp2[szX - 1][szY - 1] < 0 ? -dp2[szX - 1][szY - 1] + 1 : 1;
    }
};