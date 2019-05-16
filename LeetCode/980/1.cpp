#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int rx, ry;

    struct Node {
        int x, y;
        vector<vector<bool>> vis;
        int step;
    };
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        rx = grid.size();
        ry = grid[0].size();
        
        int obstacle = 0;
        int startX, startY;
        for(int i = 0; i < rx; i++)
        {
            for(int j = 0; j < ry; j++)
            {
                if(grid[i][j] == -1)
                {
                    obstacle++;
                }
                else if(grid[i][j] == 1)
                {
                    startX = i; startY = j;
                }
            }
        }

        vector<vector<bool>> vec(rx, vector<bool>(ry));
        for(int i = 0; i < rx; i++)
        {
            for(int j = 0; j < ry; j++)
            {
                vec[i][j] = false;
            }
        }

        queue<Node> Q;
        Node start = {startX, startY, copyVector(vec), 1};
        start.vis[startX][startY] = true;
        Q.push(start);
        int ans = 0;
        while(!Q.empty())
        {
            Node n = Q.front();
            Q.pop();
            if(grid[n.x][n.y] == 2 && n.step == (rx * ry - obstacle))
            {
                ans++;
                continue;
            }

            for(int i = 0; i < 4; i++)
            {
                int newX = n.x + dx[i];
                int newY = n.y + dy[i];
                if(isInRange(n.x + dx[i], n.y + dy[i], n.vis, grid))
                {
                    Node next = {newX, newY, {}, n.step + 1};
                    next.vis.assign(n.vis.begin(), n.vis.end());
                    next.vis[newX][newY] = true;
                    Q.push(next);
                }
            }
        }
        return ans;
    }
    bool isInRange(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& grid)
    {
        return x >= 0 && x < rx && y >= 0 && y < ry && !vis[x][y] && grid[x][y] != -1;
    }

    vector<vector<bool>> copyVector(vector<vector<bool>>& origin)
    {
        vector<vector<bool>> ret(rx, vector<bool>(ry));
        for(int i = 0; i < rx; i++)
        {
            for(int j = 0; j < ry; j++)
            {
                ret[i][j] = origin[i][j];
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> params = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    int ans = s.uniquePathsIII(params);
    cout << ans << endl;
    return 0;
}