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

typedef long long LL;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> mem(A[0].size(), 1);
        for(int i = 0; i < A[0].size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                for(int k = 0; k <= A.size(); k++)
                {
                    if(k == A.size()) {
                        mem[i] = max(mem[i], mem[j] + 1);
                    }
                    else if(A[k][j] > A[k][i])
                    {
                        break;
                    }
                }
            }
        }

        return A[0].size() - *max_element(begin(mem), end(mem));
    }
};