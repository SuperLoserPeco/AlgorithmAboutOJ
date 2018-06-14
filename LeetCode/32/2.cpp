#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int val[100000];
    int longestValidParentheses(string s) {
        int sz = s.length();
        int ans = 0;
        int cur = 0;
        int ceng = 0;
        for(int i = 0; i < sz; i++) {
            if(s[i] == '(') {
                val[i] = ceng;
                ceng++;
            }
            else if(s[i] == ')') {
                ceng--;
                val[i] = ceng;
            }
        }
        for(int i = 0; i < sz; i++)
            for(int j = i + 1; j < sz; j++) {
                if(val[j] < val[i]) {
                    break;
                }
                else if(val[j] == val[i] && s[i] == '(' && s[j] == ')') {
                    // cout << i << "-----" << j << endl;
                    ans = max(ans, (j - i + 1));
                }
            }
        return ans;
    }
};