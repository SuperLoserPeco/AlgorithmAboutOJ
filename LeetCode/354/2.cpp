#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:

    vector<int> dp;

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int cnt = 0;
        int sz = envelopes.size();

        sort(envelopes.begin(), envelopes.end());
        
        dp.resize(sz + 2);
        int ret = 0;
        for(int i = 0; i < sz; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(envelopes[j].first < envelopes[i].first &&
                    envelopes[j].second < envelopes[i].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};