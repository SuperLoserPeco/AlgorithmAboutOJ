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
        ans = 1;
        dp = new int[sz];
        for(int i = 0; i < sz; i++)
        {
            dp[i] = 1;
        }
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < vec[i].size(); j++)
            {
                int cur = vec[i][j];
                dp[cur] = max(dp[cur], dp[i] + 1);
                ans = max(ans, dp[cur]);
            }
        }
        return ans;
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