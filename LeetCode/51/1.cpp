#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    int locate[100000];
    bool visLeft[100000];
    bool visMid[100000];
    bool visRight[100000];
    void dfs(int dep, int n) {
        if (dep == n) {
            vector<string> result;
            for(int i = 0; i < n; i++) {
                string s = "";
                for(int j = 0; j < n; j++) {
                    s = s + (j == locate[i] ? "Q" : ".");
                }
                result.push_back(s);
            }
            ans.push_back(result);
            return;   
        }

        for(int i = 0; i < n; i++) {
            if(!visLeft[i - dep + n] && !visMid[i] && !visRight[i + dep]) {
                visLeft[i - dep + n] = true;
                visMid[i] = true;
                visRight[i + dep] = true;
                locate[dep] = i;
                dfs(dep + 1, n);
                visLeft[i - dep + n] = false;
                visMid[i] = false;
                visRight[i + dep] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0; i < 2 * n; i++)
            visLeft[i] = visMid[i] = visRight[i] = false;
        dfs(0, n);
        return ans;
    }
};