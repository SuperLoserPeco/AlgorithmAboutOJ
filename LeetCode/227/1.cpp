#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> op;
    vector<int> num;

    int calc(int l) {
        if(l >= op.size()) {
            int sz = num.size();
            if(sz == 1) return num[0];
            if(op[sz - 2] == 1 || op[sz - 2] == 2) return num[sz];
            else return 0;
        }
        int ret = num[l];
        while(op[l] == 3 || op[l] == 4 && l < op.size()) {
            if(op[l] == 3) ret = ret * num[l + 1];
            else if(op[l] == 4) ret = ret / num[l + 1];
            l++;
        }
        while(op[l + 1] == 1 || op[l + 1] == 2 && l + 1 < op.size()) {
            if(op[l] == 1) ret = ret - num[l + 1];
            else if(op[l] == 2) ret = ret + num[l + 1];
            l++;
        }
        if(op[l] == 1) {
            return ret - calc(l + 1);
        }
        else {
            return ret + calc(l + 1);
        }
    }

    int calculate(string s) {
        int sz = s.length();
        int cur = 0;
        while(cur < sz) llex(s, cur);
        return calc(0);
    }

    void llex(string& s, int& pc) {
        switch (s[pc]) {
            case ' ': {
                pc++;
                break;
            }
            case '-': {
                pc++;
                op.push_back(1);
                break;
            }
            case '+': {
                pc++;
                op.push_back(2);
                break;
            }
            case '*': {
                pc++;
                op.push_back(3);
                break;
            }
            case '/': {
                pc++;
                op.push_back(4);
                break;
            }
            default: {
                int digit = s[pc++] - '0';
                while(s[pc] >= '0' && s[pc] <= '9') {
                    digit *= 10;
                    digit += (s[pc] - '0');
                    pc++;
                }
                num.push_back(digit);
                break;
            }
        }
    }
};