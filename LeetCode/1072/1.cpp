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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> mp;
        int szX = matrix.size();
        if(szX == 0)
        {
            return 0;
        }
        for(int i = 0; i < szX; i++)
        {
            string s = "1";
            for(int j = 1; j < matrix[i].size(); j++)
            {
                s += ((matrix[i][j] == matrix[i][0]) ? "1" : "0");
            }
            mp[s]++;
        }
        int ret = 1;
        for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            ret = max(ret, it->second);
        }
        return ret;
    }
};

int main() {
    
    return 0;
}