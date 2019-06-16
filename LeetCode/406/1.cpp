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
    bool static cmp(vector<int>& a, vector<int>& b)
    {

        if(a[0] != b[0])
        {
            return a[0] > b[0];
        }
        else{
            return a[1] < b[1];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ret;
        int sz = people.size();
        for(int i = 0; i < sz; i++)
        {
            ret.insert(ret.begin() + people[i][1], people[i]);
        }
        return ret;
    }
};

int main() {
    
    return 0;
}