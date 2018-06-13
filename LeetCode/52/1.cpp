#include <vector>
#include <string>
using namespace std;
//不出意外 会TLE
//结果却过了 leetcode  真水
class Solution {
public:
    int locate[100000];
    bool visLeft[100000];
    bool visMid[100000];
    bool visRight[100000];
    int ans;
    void dfs(int dep, int n) {
        if (dep == n) {
            ans++;
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
    int totalNQueens(int n) {
        for(int i = 0; i < 2 * n; i++)
            visLeft[i] = visMid[i] = visRight[i] = false;
        ans = 0;
        dfs(0, n);
        return ans;   
    }
};