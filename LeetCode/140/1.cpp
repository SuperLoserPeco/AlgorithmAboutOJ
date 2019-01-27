#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    unordered_map<string, vector<string>> hash;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(int i = 0; i < wordDict.size(); i++)
        {
            words.insert(wordDict[i]);
        }
        return dfs(s, words);
    }

    vector<string> dfs(string s, unordered_set<string>& wordDict)
    {
        if(hash.count(s) > 0)
        {
            return hash[s];
        }
        vector<string> ret;
        if(wordDict.count(s) > 0)
        {
            ret.push_back(s);
        }
        for(int i = 1; i < s.length(); i++)
        {
            string first = s.substr(0, i);
            if(wordDict.count(first) > 0)
            {
                vector<string> ans = dfs(s.substr(i), wordDict);
                for(auto val: ans)
                {
                    ret.push_back(first + " " + val);
                }
            }
        }
        hash[s] = ret;
        return ret;
    }
};