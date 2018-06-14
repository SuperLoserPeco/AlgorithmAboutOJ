#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int sLen;
    int pLen;
    bool ret;
    void dfs(int si, int pi, string& s, string& p) {
        if(ret) return;
        if(si == sLen) {
            if(pi == pLen) ret = true;
            else {
                for(int i = pi; i < pLen; i++) {
                    if(p[i] != '*' && (i + 1 >= pLen || p[i + 1] != '*')) {
                        return;
                    }
                }
                ret = true;
            }
        }
        else if(pi == pLen) return;
        else {
            if(s[si] == p[pi]) {
                if(pi + 1 < pLen && p[pi + 1] == '*') {
                    for(int k = si; k < sLen; k++) {
                        if(s[k] == p[pi]) {
                            dfs(k + 1, pi + 2, s, p);
                        }
                        else {
                            break;
                        }
                    }
                    dfs(si, pi + 2, s, p);
                }
                else
                    dfs(si + 1, pi + 1, s, p);
            }
            else if(p[pi] == '.') {
                if(pi + 1 < pLen && p[pi + 1] == '*') {
                    for(int k = si; k < sLen; k++)
                        dfs(k + 1, pi + 2, s, p);
                    dfs(si, pi + 2, s, p);
                }
                else
                    dfs(si + 1, pi + 1, s, p);
            }
            else {
                if(pi + 1 < pLen && p[pi + 1] == '*')
                    dfs(si, pi + 2, s, p);
                else
                    return;
            }
        }
    }
    bool isMatch(string s, string p) {
        sLen = s.length();
        pLen = p.length();
        ret = false;
        if(!sLen) {
            bool flag = true;
            for(int i = 0; i < pLen; i++) {
                if(p[i] != '*' && ((i + 1 >= pLen) || p[i + 1] != '*'))
                    flag = false;
            }
            return flag;
        }
        dfs(0, 0, s, p);
        return ret;
    }
};