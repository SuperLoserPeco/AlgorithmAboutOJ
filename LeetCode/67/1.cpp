#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sum = str2bs(a) + str2bs(b);
        // cout << str2bs(a) << endl;
        // cout << str2bs(b) << endl;
        return bs2str(sum);
    }

    int str2bs(string &s) {
        int ret = 0;
        int sz = s.length();
        
        for(int i = 0; i < sz; i++) {
            ret <<= 1;
            ret |= (s[i] - '0');
        }
        return ret;
    }

    string bs2str(int i) {
        cout << i << endl;
        string ret = "";
        if(!i) return "0";
        while(i) {
            //要加括号 &优先级有点低
            char c = (char)((i & 1) + '0');
            cout << "char c = " << c << endl;
            ret = ret + c;
            // cout << "ret = " << ret << endl;
            i >>= 1;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};