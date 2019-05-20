#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int sz = paths.size();
        vector<vector<int>> mp(N + 1, vector<int>());
        vector<int> color(N);
        for(int i = 0; i < N; i++)
        {
            color[i] = -1;
        }
        for(int i = 0; i < sz; i++)
        {
            int x = paths[i][0];
            int y = paths[i][1];
            if(find(mp[x].begin(), mp[x].end(), y) == mp[x].end())
            {
                mp[x].push_back(y);
            }            
            if(find(mp[y].begin(), mp[y].end(), x) == mp[y].end())
            {
                mp[y].push_back(x);
            }
        }
        for(int i = 0; i < N; i++)
        {
            int current = 1;
            while(true)
            {
                bool isColored = false;
                for(int j = 0; j < mp[i + 1].size(); j++)
                {
                    if(color[mp[i + 1][j] - 1] == current)
                    {
                        isColored = true;
                    }
                }
                if(!isColored)
                {
                    break;
                }
                else{
                    current++;
                }
            }
            color[i] = current;
        }
        return color;
    }
};

int main() {
    
    return 0;
}