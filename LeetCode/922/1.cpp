#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ret;
        int sz = A.size();
        for(int i = 0; i < sz; i++)
        {
            ret.push_back(0);
        }
        int cnt = 0;
        for(int i = 0; i < sz; i++)
        {
            if(A[i] % 2 == 0)
            {
                ret[cnt] = A[i];
                cnt += 2;
            }
        }

        cnt = 1;
        for(int i = 0; i < sz; i++)
        {
            if(A[i] % 2 == 1)
            {
                ret[cnt] = A[i];
                cnt += 2;
            }
        }
        
        return ret;
    }
};