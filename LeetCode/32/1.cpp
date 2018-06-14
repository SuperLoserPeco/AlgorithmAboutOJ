
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.length();
        int ans = 0;
        int cur = 0;
        int ceng = 0;
        for(int i = 0; i < sz; i++) {
            if(s[i] == '(') ceng++;
            else if(s[i] == ')') ceng--;

            if(ceng >= 0) cur++;
            if(ceng == 0) ans = max(ans, cur);
        }
        return ans;
    }
};