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
    int arrayNesting(vector<int>& nums) {
        int sz = nums.size();
        bool* vis = new bool[sz];
        int ans = 0;
        for(int i = 0; i < sz; i++)
        {
            vis[i] = false;
        }
        for(int i = 0; i < sz; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                int next = nums[i];
                int cnt = 1;
                while(next != i)
                {
                    vis[next] = true;
                    cnt++;
                    next = nums[next];
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}