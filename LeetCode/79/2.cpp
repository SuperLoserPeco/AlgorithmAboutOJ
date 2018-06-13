#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;


class Solution {
public:
    struct Step {
        int x, y;
        int step;
    };
    bool flag;
    int n, m;

    map<int, bool> vis;

    void dfs(Step step, int cur, 
                vector<vector<char>>& board, string& word) {
        if(flag) return;

        if(board[step.x][step.y] == word[cur]) {
            if(cur == word.length() - 1){
                flag = true;
                return ;
            }
            int dx[] = {1, 0, 0, -1};
            int dy[] = {0, 1, -1, 0};
            for(int i = 0; i < 4; i++) {
                Step nstep;
                nstep.x = step.x + dx[i];
                nstep.y = step.y + dy[i];
                if(nstep.x >= 0 && nstep.x < n && 
                    nstep.y >= 0 && nstep.y < m &&
                    !vis[nstep.x * m + nstep.y]) {
                    vis[nstep.x * m + nstep.y] = true;
                    dfs(nstep, cur + 1, board, word);
                    vis[nstep.x * m + nstep.y] = false;
                }
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        vis.clear();

        n = board.size();
        m = board[0].size();
        if(n == 0 || m == 0)
            return word.length() == 0;

        flag = false;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                Step step;
                step.x = i; step.y = j;
                step.step = 0;
                vis[i * m + j] = true;
                dfs(step, 0, board, word);
                vis[i * m + j] = false;
            }
        }


        return flag;
    }
};