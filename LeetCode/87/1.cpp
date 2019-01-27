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
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
        {
            return false;
        }
        int sz = s1.length();
        return dfs(0, sz, s2, s1);
    }

    bool dfs(int l, int r, string s, string& s1)
    {
        int mid = (l + r) / 2;
        map<char, int> mpL1;
        map<char, int> mpR1;
        map<char, int> mpL2;
        map<char, int> mpR2;

        //no fanzhuan
        bool eqResult = true;
        for(int i = l; i < mid; i++)
        {
            mpL1[s[i - l] - 'a']++;
            mpR1[s1[i] - 'a']++;
            if(s[i - l] != s1[i])
            {
                eqResult = false;
            }
        }
        for(int i = mid; i < r; i++)
        {
            mpL2[s[i - l] - 'a']++;
            mpR2[s1[i] - 'a']++;
            if(s[i - l] != s1[i])
            {
                eqResult = false;
            }
        }
        if(eqResult)
        {
            return true;
        }
        bool flag = true;
        for(int i = 0; i < 26; i++)
        {
            if(mpL1[i] != mpR1[i]) {
                flag = false;
                break;
            }
            if(mpL2[i] != mpR2[i])
            {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(r - l == 1)
            {
                return true;
            }
            bool left = dfs(l, mid, s.substr(0, (mid - l)), s1);
            bool right = dfs(mid, r, s.substr(mid, (r - mid)), s1);
            if(left && right)
            {
                return true;
            }
        }

        if(r - l > 1)
        {
            mpL1.clear();
            mpL2.clear();
            mpR1.clear();
            mpR2.clear();

            eqResult = true;
            for(int i = l; i < mid; i++)
            {
                mpL1[s[i - l] - 'a']++;
                mpR1[s1[i + (r - mid)] - 'a']++;
                if(s[i - l] != s1[i + (r - mid)])
                {
                    eqResult = false;
                }
            }
            for(int i = mid; i < r; i++)
            {
                mpL2[s[i - l] - 'a']++;
                mpR2[s1[i - (mid - l)] - 'a']++;
                if(s[i - l] != s1[i - (mid - l)])
                {
                    eqResult = false;
                }
            }
            if(eqResult)
            {
                return true;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++)
            {
                if(mpL1[i] != mpR1[i]) {
                    flag = false;
                    break;
                }
                if(mpL2[i] != mpR2[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                if(r - l == 1)
                {
                    return true;
                }
                bool left = dfs(l + (r - mid), r, s.substr(0, (mid - l)), s1);
                bool right = dfs(l, r - (mid - l), s.substr(mid, (r - mid)), s1);
                if(left && right)
                {
                    return true;
                }
            }
        }

        return false;
    }
};