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
    int minAddToMakeValid(string S) {
        int sz = S.length();
        int resR = 0;
        int leftNum = 0;
        for(int i = 0; i < sz; i++)
        {
            if(S[i] == '(')
            {
                leftNum++;
            }
            else {
                if(leftNum > 0)
                {
                    leftNum--;
                }
                else{
                    resR++;
                }
            }
        }
        return leftNum + resR;
    }
};