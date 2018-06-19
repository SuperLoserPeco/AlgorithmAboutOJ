#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    struct Node {
        int x, y;
        int val;
        bool operator < (const Node& rhs) {
            return val < rhs.val;
        }
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        vector<Node> vec;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m ;j++) {
            Node nd;
            nd.x = i; nd.y = j; nd.val = matrix[i][j];
            vec.push_back(nd);
        }
        sort(vec.begin(), vec.end());
        int sz = vec.size();
        map<int, int> mp;
        for(int i = 0; i < sz; i++) {
            int posX = vec[i].x;
            int posY = vec[i].y;
            mp[posX * m + posY] = 1;
        }
        for(int i = 0; i < sz; i++) {
            int dx[] = {0, 1, -1, 0};
            int dy[] = {1, 0, 0, -1};
            int posX = vec[i].x;
            int posY = vec[i].y;
            for(int j = 0; j < 4; j++) {
                int nx = posX + dx[j];
                int ny = posY + dy[j];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if(matrix[nx][ny] < matrix[posX][posY]) {
                        mp[posX * m + posY] = max(mp[posX * m + posY], mp[nx * m + ny] + 1);
                    }
                }
            }
        }
        int ret = 1;
        for(int i = 0; i < sz; i++) {
            ret = max(ret, mp[vec[i].x * m + vec[i].y]);
        }
        return ret;
    }
};