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
#include <unordered_map>
using namespace std;

typedef long long LL;


class Solution {
public:
    struct Node{
        int left, right;
    };
    static bool cmp(const Node& a, const Node& b) {
        return a.left < b.left;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<int> ans(sz, -1);

        vector<Node> nodes(sz);
        if(sz == 0)
        {
            return ans;
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < sz; i++)
        {
            nodes[i].left = intervals[i][0];
            nodes[i].right = intervals[i][1];
            mp[nodes[i].left] = i;
        }
        sort(nodes.begin(), nodes.end(), cmp);

        for(int i = 0; i < sz; i++)
        {
            for(int j = i + 1; j < sz; j++)
            {
                if(nodes[j].left >= nodes[i].right)
                {
                    ans[mp[nodes[i].left]] = mp[nodes[j].left];
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}