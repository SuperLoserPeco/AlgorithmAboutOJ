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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> leaves;
        if(n == 1)
        {
            leaves.push_back(0);
            return leaves;
        }
        vector<set<int>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        for(int i = 0; i < n; i++)
        {
            if(adj[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }
        while(n > 2)
        {
            n -= leaves.size();
            vector<int> newLeaves;
            for(auto i : leaves)
            {
                for(auto j : adj[i])
                {
                    adj[j].erase(i);
                    if(adj[j].size() == 1)
                    {
                        newLeaves.push_back(j);
                    }
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

int main() {
    
    return 0;
}