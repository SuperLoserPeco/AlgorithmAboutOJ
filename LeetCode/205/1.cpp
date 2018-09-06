#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>
#include <map>  
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool* vis = new bool[numCourses];
        for(int i = 0; i < numCourses; i++) {
            vis[i] = false;
        }
        return true;
    }
};