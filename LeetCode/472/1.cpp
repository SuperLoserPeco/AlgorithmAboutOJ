
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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        if(words.size() == 1)
        {
            return ret;
        }
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });

        set<string> setStr;
        for(auto item :words) {
            if(isOK(setStr, item))
            {
                ret.push_back(item);
            }
            setStr.insert(item);
        }
        return ret;
    }

    bool isOK(set<string>& setStr, string& item) {
        if(setStr.empty())
        {
            return false;
        }
        int len = item.size();
        bool dp[len + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 1; i <= len; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j] && setStr.find(item.substr(j, i - j)) != setStr.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};