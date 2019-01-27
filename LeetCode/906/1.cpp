#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;
//https://zhanghuimeng.github.io/post/leetcode-906-super-palindromes/
class Solution {
public:
    LL s2l(string str)
    {
        LL x = 0;
        for(int i = 0; i < str.length(); i++)
        {
            x = x * 10 + (str[i] - '0');
        }
        return x;
    }

    int superpalindromesInRange(string L, string R) {
        int sum = 0;
        LL l = s2l(L), r = s2l(R);
        for(int a0 = 0; a0 <= 3; a0++)
        {
            for(int a1 = 0; a1 <= 3; a1++)
            {
                for(int a2 = 0; a2 <= 3; a2++)
                {
                    for(int a3 = 0; a3 <= 3; a3++)
                    {
                        for(int a4 = 0; a4 <= 3; a4++)
                        {

                        }
                    }
                }
            }
        }
    }
};