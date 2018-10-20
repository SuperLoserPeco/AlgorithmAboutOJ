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
        string alphas = "";
        for(int i = 0; i < sz; i++)
        {
            if(isAlpha(S[i]))
            {
                alphas += S[i];
            }
        }
        reverse(alphas.begin(), alphas.end());

        string ret = "";
        int cnt = 0;
        for(int i = 0; i < sz; i++)
        {
            if(isAlpha(S[i]))
            {
                ret += alphas[cnt];
                cnt++;
            }
            else{
                ret += S[i];
            }
        }
        return ret;
    }

    bool isAlpha(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
};