#include <vector>
#include <string>
#include <iostream>
#include <algorithm>e:
using namespace std;

//优先队列 +BFS

class Solution {
public:
    int* horizontal;    //水平
    int* vertical;      //垂直
    int* cell;

    struct Pos {
        int x, y;
        int restTime;
        int ans;
        bool operator<(Pos& rhs) const {
            return restTime < rhs.restTime;
        }
    };

    vector<Pos> vec;
    bool isExist = false;

    void solveSudoku(vector<vector<char>>& board) {
        vertical = new int[9];
        horizontal = new int[9];
        cell = new int[9];
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            int state = 0;
            for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) {
                int x = i * 3 + k;
                int y = j * 3 + l;

                int cur;
                if(board[x][y] == '.') {
                    cur = -1;
                }
                else {
                    cur = board[x][y] - '0';
                    state |= (1 << cur);
                }
            }
            cell[i * 3 + j] = state;
        }

        for(int i = 0; i < 9; i++) {
            int state = 0;
            for(int j = 0; j < 9; j++) {
                int cur;
                if(board[i][j] == '.') {
                    cur = -1;
                }
                else {
                    cur = board[i][j] - '0';
                    state |= (1 << cur);
                }
            }
            horizontal[i] = state;
        }

        for(int i = 0; i < 9; i++) {
            int state = 0;
            for(int j = 0; j < 9; j++) {
                int cur;
                if(board[j][i] == '.') {
                    cur = -1;
                }
                else {
                    cur = board[j][i] - '0';
                    state |= (1 << cur);
                }
            }
            vertical[i] = state;
        }

        vec.clear();
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++)
            for(int l = 0; l < 3; l++) {
                int x = i * 3 + k;
                int y = j * 3 + l;

                if(board[x][y] == '.') {
                    Pos pos;
                    pos.x = x;
                    pos.y = y;
                    int nowstate = cell[i * 3 + j] | 
                                    vertical[y] | horizontal[x];
                    cout << x << "---" << y << endl;    
                    PrintState(nowstate);
                    pos.restTime = 9 - calcState(nowstate);
                    vec.push_back(pos);
                }
            }
        }
        sort(vec.begin(), vec.end());

        isExist = false;
        dfs(0);
        if(isExist) {
            for(int i = 0; i < vec.size(); i++) {
                board[vec[i].x][vec[i].y] = '0' + vec[i].ans;
            }
        }
    }

    int calcState(int state) {
        int ret = 0;
        for(int i = 0; i < 9; i++) {
            if(state & (i << 1)) ret++;
        }
        return ret;
    }

    bool isRepeat(int state1, int state2, int state3) {
        for(int i = 0; i < 9; i++) {
            int cnt = 0;
            if((1 << i) & state1) cnt++;
            if((1 << i) & state2) cnt++;
            if((1 << i) & state3) cnt++;
            if(cnt > 1) return false;
        }
        return true;
    }

    void dfs(int dep) {
        if(dep >= vec.size()) {
            isExist = true;
            return;
        }
        if(isExist) return;

        int x = vec[dep].x;
        int y = vec[dep].y;
        int cellX = vec[dep].x / 3;
        int cellY = vec[dep].y / 3;

        int nowstate = horizontal[x] | vertical[y] | cell[cellX * 3 + cellY];
        

        for(int i = 1; i <= 9; i++) {
            if(((1 << i) & nowstate) == 0) {
                vec[dep].ans = i;
                horizontal[x] += (1 << i);
                vertical[y] += (1 << i);
                cell[cellX * 3 + cellY] += (1 << i);
                dfs(dep + 1);
                if(isExist) return;

                horizontal[x] -= (1 << i);
                vertical[y] -= (1 << i);
                cell[cellX * 3 + cellY] -= (1 << i);
            }
        }
    }

    void PrintState(int state) {
        for(int i = 9; i >= 1; i--) {
            cout << ((state & (1 << i)) > 0 ? "1" : "0") ;
        }
        cout << endl;
    }
};