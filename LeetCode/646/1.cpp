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
    vector<vector<int>> vec;
    vector<int> dp;
    int findLongestChain(vector<vector<int>>& pairs) {
        int sz = pairs.size();
        vec.resize(sz + 1);
        dp.resize(sz + 1);
        for(int i = 0; i < sz; i++)
        {
            dp[i] = 0;
        }
        for(int i = 0; i < sz; i++)
        {
            for(int j = i + 1; j < sz; j++)
            {
                if(pairs[i][1] < pairs[j][0])
                {
                    vec[i].push_back(j);
                }
                else if(pairs[j][1] < pairs[i][0]){
                    vec[j].push_back(i);
                }
            }
        }
        int ret = 1;
        for(int i = 0; i < sz; i++)
        {
            ret = max(ret, dfs(i));
        }
        return ret;
    }
    int dfs(int u)
    {
        if(dp[u] != 0)
        {
            return dp[u];
        }
        int sz = vec[u].size();
        int current = 1;
        for(int i = 0; i < sz; i++)
        {
            current = max(current, dfs(vec[u][i]) + 1);
        }
        return dp[u] = current;
    }
};

int main() {
    
    return 0;
}