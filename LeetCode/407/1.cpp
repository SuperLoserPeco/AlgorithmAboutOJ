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

class Solution {
    struct Node{
        int x, y, h; 
        Node(int x, int y, int h)
        {
            this->x = x;
            this->y = y;
            this->h = h;
        }
        bool operator<(const Node& rhs) const{
            return h > rhs.h;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        priority_queue<Node, vector<Node>> Q;
        int row = heightMap.size();
        int col = row == 0 ? 0 : heightMap[0].size();
        if(row < 3 || col < 3)
        {
            return 0;
        }
        vector<vector<bool>> vis(row, vector<bool>());
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                vis[i].push_back(false);
            }
        }
        for(int i = 0; i < row; i++)
        {
            Q.push(Node(i, 0, heightMap[i][0]));
            Q.push(Node(i, col - 1, heightMap[i][col - 1]));

            vis[i][0] = true;
            vis[i][col - 1] = true;
        }
        for(int i = 1; i < col - 1; i++)
        {
            Q.push(Node(0, i, heightMap[0][i]));
            Q.push(Node(row - 1, i, heightMap[row - 1][i]));

            vis[0][i] = true;
            vis[row - 1][i] = true;
        }

        int ans = 0;
        while(!Q.empty())
        {
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if((nx < 0 || nx >= row || ny < 0 || ny >= col))
                {
                    continue;
                }
                if(vis[nx][ny])
                {
                    continue;
                }
                if(h > heightMap[nx][ny])
                {
                    ans += (h - heightMap[nx][ny]);
                    heightMap[nx][ny] = h;
                }
                Q.push(Node(nx, ny, heightMap[nx][ny]));
                vis[nx][ny] = true;
            }
        }

        return ans;    
    }
};

int main() {
    vector<vector<int>> vec = {{1, 2, 2}, {1, 3, 4}};
    return 0;
}