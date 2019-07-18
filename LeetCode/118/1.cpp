#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;

        vector<int> row0;
        if(numRows == 0)
        {
            return ret;
        }
        row0.push_back(1);
        ret.push_back(row0);

        for(int i = 2; i <= numRows; i++)
        {
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i - 1; j++)
            {
                row.push_back(ret[i - 2][j - 1] + ret[i - 2][j]);
            }
            row.push_back(1);

            ret.push_back(row);
        }

        return ret;
    }
};

int main() {
    
    return 0;
}