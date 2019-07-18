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
public:
    int mxHeight;
    vector<int> node;

    int dfs(int u, int fa, int dep)
    {
        int mxDep = dep;
        int sz = graph[u].size();
        for(int i = 0; i < sz; i++)
        {
            if(graph[u][i] == fa)
            {
                continue;
            }
            int currentDep = dfs(graph[u][i], u, dep + 1);
            mxDep = max(mxDep, currentDep);
        }
        if(mxDep < mxHeight)
        {
            mxHeight = mxDep;
            node.clear();
            node.push_back(u);
        }
        else if(mxDep == mxHeight)
        {
            node.push_back(u);
        }
        return dep + 1;
    }

    vector<vector<int>> graph;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        mxHeight = n;
        graph.resize(n + 1);
        int count = edges.size();
        for(int i = 0; i < count; i++)
        {
            int countY = edges[i].size();
            for(int j = 0; j < countY; j++)
            {
                if(i != edges[i][j])
                {
                    cout << i << "--" << edges[i][j] << endl;
                    graph[i].push_back(edges[i][j]);
                    graph[edges[i][j]].push_back(i);
                }
            }
        }
        for(int i = 0; i < count; i++)
        {
            if(graph[i].size() == 1)
            {
                dfs(i, -1, 0);
                break;
            }
        }
        return node;
    }
};

int main() {
    
    return 0;
}