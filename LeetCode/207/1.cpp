#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>
#include <iostream>  
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool* vis = new bool[numCourses];
        for(int i = 0; i < numCourses; i++)
            vis[i] = false;

        queue<int> Q;
        while(!Q.empty()) Q.pop();
        if(prerequisites.size() == 0) return true;
        Q.push(prerequisites[0].second);
        while(!Q.empty()) {
            int now = Q.front(); Q.pop();
            if(vis[now]) {
                return false;
            }

            for(int i = 0; i < prerequisites.size(); i++) {
                cout << "--- " << i << endl;
                cout << prerequisites[i].second << endl;
                if(prerequisites[i].second == now) {
                    vis[now] = true;
                    cout << "--- " << i << endl;
                    Q.push(prerequisites[i].first);
                    prerequisites.erase(prerequisites.begin() + i);
                    i--;
                }
            }
        }
        return true;
    }
};