#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string dfs(int r, int& iter, string& s) {
        string ret = "";
        while(iter < r && s[iter] != ']') {
            cout << iter << endl;
            if(s[iter] >= '0' && s[iter] <= '9') {
                int num = 0;
                while(iter < r && s[iter] >= '0' && s[iter] <= '9') {
                    num *= 10;
                    num += (s[iter] - '0');
                    iter++;
                }
                iter++;
                string repeatS = dfs(r, iter, s);
                for(int i = 0; i < num; i++)
                    ret = ret + repeatS;
            }
            else {
                ret = ret + s.substr(iter, 1);
                iter++;
            }

        }
        if(iter < r && s[iter] == ']') iter++;
        return ret;
    }

    string decodeString(string s) {
        int sz = s.length();
        int iter = 0;
        return dfs(sz, iter, s);
    }
};