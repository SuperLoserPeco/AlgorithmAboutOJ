#include <vector>
#include <string>
#include <iostream>
using namespace std;

//手撸 KMP

class Solution {
public:
    string sadd(string a, string b) {
        string ret = "";
        int la = a.length() - 1;
        int lb = b.length() - 1;
        int step = 0;
        while(la >= 0 && lb >= 0) {
            int curNum = a[la] - '0' + b[lb] - '0' + step;
            
        }
    }

    string multiply(string num1, string num2) {
        
    }
};