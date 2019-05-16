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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int szR = image.size();
        if(szR == 0)
        {
            return image;
        }      
        int szC = image[0].size();

        int baseColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(make_pair<int, int>((int)sr, (int)sc));
        map<int, bool> vis;
        while(!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();
            image[current.first][current.second] = newColor;
            vis[current.first * szC + current.second] = true;
            for(int i = 0; i < 4; i++)
            {
                int newX = current.first + dx[i];
                int newY = current.second + dy[i];
                if(newX >= 0 && newX < szR && newY >= 0 && newY < szC)
                {
                    if(!vis[newX * szC + newY] && image[newX][newY] == baseColor)
                    {
                        q.push(make_pair<int, int>((int)newX, (int)newY));
                    }
                }
            }
        }
        return image;
    }
};

int main() {
    
    return 0;
}