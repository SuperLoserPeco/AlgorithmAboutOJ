#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;


class Solution {
public:
    struct Step {
        int x, y;
        int step;
    };

    bool exist(vector<vector<char>>& board, string word) {
        map<int, bool> vis;
        queue<Step> Q;
        while(!Q.empty()) Q.pop();
        vis.clear();

        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                Step step;
                step.x = i; step.y = j;
                step.step = 0;
                Q.push(step);
            }
        }

        int dx[] = {1, -1};
        int dy[] = {1, -1};

        while(!Q.empty()) {
            Step cur = Q.front();
            Q.pop();
            if(board[cur.x][cur.y] == word[cur.step]) {
                if(cur.step == word.length() - 1)
                    return true;
                else {

                }
            }
        }

        return false;
    }
};