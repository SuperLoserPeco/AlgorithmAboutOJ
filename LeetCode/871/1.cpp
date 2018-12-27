#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<pair<int, int>> que;
        int ans = 0, pos = 0, tank = startFuel;
        vector<int> vec;
        vec.push_back(target);
        vec.push_back(0);
        stations.push_back(vec);
        for(int i = 0; i < stations.size(); i++)
        {
            int curDist = stations[i][0] - pos;
            while(curDist > tank)
            {
                if(que.empty())
                {
                    return -1;
                }

                pair<int, int> temp = que.top();
                que.pop();

                tank += temp.first;
                ans++;
            }

            tank -= curDist;
            pos = stations[i][0];

            que.push(make_pair(stations[i][1], i));
        }
        return ans;
    }
};