#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:

    vector<int> vec[13000];
    map<pair<int, int>, int> mp;
    vector<int> dp;

    int dfs(int i) {
        if(dp[i] != -1) return dp[i];
        int ret = 1;
        int sub = 0;
        int sz = vec[i].size();
        for(int j = 0; j < sz; j++) {
            sub = max(sub, dfs(vec[i][j]));
        }
        return dp[i] = ret + sub;
    }

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int cnt = 0;
        int sz = envelopes.size();
        for(int i = 0; i < sz; i++) {
            if(mp[envelopes[i]] == 0) mp[envelopes[i]] = ++cnt;
            for(int j = i + 1; j < sz; j++) {
                if(mp[envelopes[j]] == 0) mp[envelopes[j]] = ++cnt;
                if(envelopes[i].first < envelopes[j].first &&
                    envelopes[i].second < envelopes[j].second) 
                        vec[mp[envelopes[i]]].push_back(mp[envelopes[j]]);
                if(envelopes[i].first > envelopes[j].first &&
                    envelopes[i].second > envelopes[j].second) 
                        vec[mp[envelopes[j]]].push_back(mp[envelopes[i]]);
            }
        }
        cout << cnt << endl;
        dp.resize(cnt + 1);
        for(int i = 1; i <= cnt; i++) dp[i] = -1;
        int ret = 0;
        for(int i = 1; i <= cnt; i++) {
            ret = max(ret, dfs(i));
        }
        return ret;
    }
};