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
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int szA = a.length();
        int szB = b.length();
        int sz = max(szA, szB);
        int step = 0;
        string ret = "";
        for(int i = 0; i < sz; i++) {
            int stepA = 0;
            int stepB = 0;
            if(i < szA) stepA = (a[i] - '0');
            if(i < szB) stepB = (b[i] - '0');
            int now = (stepA + stepB + step) % 2;
            int step = (stepA + stepB + step) / 2;
            ret += ((char)(now + '0'));
        }
        if(step > 0) {
            ret += ((char)(step + '0'));
        }
        if(ret == "") return "0";
        else return reverse(ret.begin(), ret.end());
    }
};