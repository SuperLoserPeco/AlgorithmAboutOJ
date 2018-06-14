#include <vector>
#include <string>
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
                    for(int k = si + 1; k < sLen; k++) {
                        if(s[k] == p[pi]) {
                            dfs(k + 1, si + 1, s, p);
                        }
                        else {
                            break;
                        }
                    }
                }
                else
                    dfs(pi + 1, si + 1, s, p);
            }
            else if(p[pi] == '.') {
                if(pi + 1 < pLen && p[pi + 1] == '*') {
                    for(int k = si + 1; k < sLen; k++)
                        dfs(k, pi + 2, s, p);
                }
                else
                    dfs(pi + 1, si + 1, s, p);
            }
            else {
                if(pi + 1 < pLen && p[pi + 1] == '*')
                    dfs(si + 1, pi + 2, s, p);
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
            for(int i = 1; i < pLen; i++) {
                if(!(p[i] == '*' && p[i - 1] != '*'))
                    flag = false;
            }
            return flag;
        }
        dfs(0, 0, s, p);
        return ret;
    }
};