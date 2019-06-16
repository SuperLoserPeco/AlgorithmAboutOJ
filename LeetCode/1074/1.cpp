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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i)
                {
                    matrix[i][j] += matrix[i - 1][j];
                }
                if(j)
                {
                    matrix[i][j] += matrix[i][j - 1];
                }
                if(i && j)
                {
                    matrix[i][j] -= matrix[i - 1][j - 1];
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                unordered_map<int, int> bag;
                bag[0] = 1;
                for(int k = 0; k < m; k++)
                {
                    int current = matrix[j][k] - (i == 0 ? 0 : matrix[i - 1][k]);
                    unordered_map<int, int>::iterator it = bag.find(current-target);
                    if(it != bag.end())
                    {
                        ans += it->second;
                    }
                    it = bag.find(current);
                    if(it != bag.end())
                    {
                        it->second++;
                    }
                    else{
                        bag.insert({current, 1});
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}