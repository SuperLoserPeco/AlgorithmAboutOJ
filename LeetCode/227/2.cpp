#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> op;
    vector<int> num;

    int priority[5] = {0, 1, 1, 2, 2};

    int calc(int& l, int _priority) {
        int ret = num[l];
        
        while(l < op.size()) {
            if(priority[l] < _priority) break;

            if(l < op.size() - 1 && priority[op[l + 1]] > priority[op[l]]) {
                int curOp = op[l];
                l++;
                int priorityRet = calc(l, priority[op[l]]);
                if(curOp == 1) ret -= priorityRet;
                else if(curOp == 2) ret += priorityRet;
            }
            else{
                //" 3+5 / 2 "
                int curOp = op[l];
                switch(curOp){
                    case 1:
                        ret -= num[l + 1];
                        break;
                    case 2:
                        ret += num[l + 1];
                        break;
                    case 3:
                        ret *= num[l + 1];
                        break;
                    case 4:
                        ret /= num[l + 1];
                        break;
                }
                l++;
            }
        }
        cout << "ret = " << ret << endl;
        return ret;
    }

    int calculate(string s) {
        int sz = s.length();
        int cur = 0;
        while(cur < sz) llex(s, cur);
        cout << op.size() << endl;
        cout << num.size() << endl;
        int iter = 0;
        return calc(iter, 0);
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