#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>

#include <algorithm>
using namespace std;

class Solution {
public:
    map<int, bool> mp[1101];
    map<int, int> locate;
    bool ans;

    void dfs(vector<int>& stones, int cur, int step) {
        if(ans) {
            return;
        }

        if(mp[cur][step]) {
            return;
        }
        mp[cur][step] = true;

        int sz = stones.size();
        int next = stones[cur] + step;

        if(locate[next] == 0) {
            return;
        }
        if(locate[next] == sz - 1) {
            ans = true;
            return;
        }

        if(step - 1 > 0) {
            dfs(stones, locate[next], step - 1);
        }
        dfs(stones, locate[next], step);
        dfs(stones, locate[next], step + 1);
    }

    bool canCross(vector<int>& stones) {
        for(int i = 0; i < 1101; i++) {
            mp[i].clear();
        }
        locate.clear();
        for(int i = 0; i < stones.size(); i++) {
            locate[stones[i]] = i;
        }
        ans = false;
        dfs(stones, 0, 1);

        return ans;
    }
};