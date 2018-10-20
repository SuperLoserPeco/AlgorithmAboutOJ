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
    string reverseOnlyLetters(string S) {
        int sz = S.length();
        int st = 0, ed = 0;
        while(st < sz && ed < sz)
        {
            if(isAlpha(S[st]))
            {
                ed = st + 1;
                while(ed < sz && isAlpha(S[ed]))
                {
                    ed++;
                }
                reverse(S.begin() + st, S.begin() + ed);
                st = ed;
            }
            else{
                st++;
            }
        }
        return S;
    }

    bool isAlpha(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
};