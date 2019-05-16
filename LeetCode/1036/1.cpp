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

#pragma comment(linker, “/STACK:1024000000,1024000000”)
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> pair1, pair2;
        set<pair<int, int>> setBlock;
        int cnt = blocked.size();
        for(int i = 0; i < cnt; i++)
        {
            int x = blocked[i][0];
            int y = blocked[i][1];
            setBlock.insert(make_pair<int, int>((int)x, (int)y));
        }
        return dfs(setBlock, source, target, pair1, 0) && dfs(setBlock, target, source, pair2, 0);
    }

    bool dfs(set<pair<int, int>>& blocked, vector<int>& source, vector<int>& target, set<pair<int, int>>& pairCurrent, int step)
    {
        if(step >= 2 * 1000000 || (source[0] == target[0] && source[1] == target[1]))
        {
            return true;
        }
        if(!isOK(source))
        {
            return false;
        }
        cout << step << endl;
        pair<int, int> current = make_pair<int, int>((int)source[0], (int)source[1]);
        if(blocked.find(current) != blocked.end() || pairCurrent.find(current) != pairCurrent.end())
        {
            return false;
        }
        
        pairCurrent.insert(current);
        vector<int> next[4];
        for(int i = 0; i < 4; i++)
        {
            next[i].push_back(source[0] + dx[i]);
            next[i].push_back(source[1] + dy[i]);
        }
        return dfs(blocked, next[0], target, pairCurrent, step + 1) || 
                dfs(blocked, next[1], target, pairCurrent, step + 1) || 
                dfs(blocked, next[2], target, pairCurrent, step + 1) || 
                dfs(blocked, next[3], target, pairCurrent, step + 1);
    }

    bool isOK(vector<int>& source)
    {
        return source[0] >= 0 && source[0] < 1000000 && source[1] >= 0 && source[1] < 1000000;
    }
};

int main() {
    
    return 0;
}