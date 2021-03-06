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
    int* dp;
    int ans;
    bool static cmp(string a, string b)
    {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        int sz = words.size();
        vector<vector<int>> vec(sz);
        sort(words.begin(), words.end(), cmp);
        for(int i = 0; i < sz; i++)
        {
            for(int j = i + 1; j < sz; j++)
            {
                if(words[i].length() == words[j].length())
                {
                    continue;
                }
                if(words[i].length() + 1 < words[j].length())
                {
                    break;
                }
                if(isChain(words[i], words[j]))
                {
                    vec[i].push_back(j);
                }
            }
        }
        ans = 0;
        dp = new int[sz];
        for(int i = 0; i < sz; i++)
        {
            dp[i] = 0;
        }
        for(int i = 0; i < sz; i++)
        {
            ans = max(ans, dfs(vec, i));
        }
        return ans;
    }

    int dfs(vector<vector<int>> vec, int cur)
    {
        if(dp[cur] != 0)
        {
            return dp[cur];
        }
        dp[cur] = 1;
        for(int i = 0; i < vec[cur].size(); i++)
        {
            dp[cur] = max(dp[cur], dfs(vec, vec[cur][i]) + 1);
        }
        return dp[cur];
    }

    bool isChain(string a, string b)
    {
        int i = 0, j = 0;
        if(a.length() + 1 != b.length())
        {
            return false;
        }
        while(i < a.length() && j < b.length())
        {
            if(a[i] == b[j])
            {
                i++; j++;
            }
            else{
                j++;
            }
        }
        return i == a.length();
    }
};

int main() {
    
    return 0;
}