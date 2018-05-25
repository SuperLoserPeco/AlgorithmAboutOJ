#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> op;
    vector<int> num;
    int calculate(string s) {
        int sz = s.length();
        int cur = 0;
        while(cur < sz) llex(s, cur);
    }

    int calc(int l) {

    }

    void llex(string& s, int& pc) {
        switch (s[pc]) {
            case ' ': {
                pc++;
            }
            case '-': {
                pc++;
                op.push_back(1);
            }
            case '+': {
                pc++;
                op.push_back(2);
            }
            case '*': {
                pc++;
                op.push_back(3);
            }
            case '/': {
                pc++;
                op.push_back(4);
            }
            default: {
                int digit = s[pc++] - '0';
                while(s[pc] >= '0' && s[pc] <= '9') {
                    digit *= 10;
                    digit += (s[pc] - '0');
                    pc++;
                }
                num.push_back(digit);
            }
        }
    }
};