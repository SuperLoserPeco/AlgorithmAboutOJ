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

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> left, right, vis;
    SummaryRanges() {
        
    }
    bool static cmp(vector<int>& vec1, vector<int>& vec2)
    {
        if(vec1[0] != vec2[0])
        {
            return vec1[0] < vec2[0];
        }
        else{
            return vec1[1] < vec2[1];
        }
    }
    void addNum(int val) {
        if(vis[val])
        {
            return;
        }
        vis[val] = 1;
        if(right.find(val + 1) != right.end())
        {
            int rightEnd = right[val + 1];
            if(left.find(val - 1) != left.end())
            {
                int leftBegin = left[val - 1];
                right.erase(val + 1);
                left.erase(val - 1);

                left[rightEnd] = leftBegin;
                right[leftBegin] = rightEnd;
            }
            else{
                right.erase(val + 1);
                right[val] = rightEnd;
                left[rightEnd] = val;
            }
        }
        else{
            if(left.find(val - 1) != left.end())
            {
                int leftBegin = left[val - 1];

                left.erase(val - 1);
                left[val] = leftBegin;
                right[leftBegin] = val;
            }
            else{
                left[val] = val;
                right[val] = val;
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(unordered_map<int, int>::iterator it = right.begin(); it != right.end(); it++)
        {
            vector<int> current;
            current.push_back(it->first);
            current.push_back(it->second);
            ans.push_back(current);
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};

int main() {
    
    return 0;
}