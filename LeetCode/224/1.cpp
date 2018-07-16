#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int iter;
    int flagToMap[5] = {0, -1, -2, -3, -4};

    int calc(string& s) {
        int sz = s.length();
        int ret = 0;
        cout << iter << "---" << sz << endl;
        while(iter < sz) {
            int val = llexNext(s);

            cout << "val = " << val << endl;
            if(val >= 0) ret += val;
            else if(val == -1 || val == -2) {
                int nval = llexNext(s);
                if(nval == -3) {
                    int nret = calc(s);
                    if(val == -1) ret += nret;
                    else if(val == -2) ret -= nret;
                }
                else if(nval > 0) {
                    if(val == -1) ret += nval;
                    else if(val == -2) ret -= nval;
                }
            }
            else if(val == -3) {
                int nret = calc(s);
                ret += nret;
            }
            else if(val == -4) {
                break;
            }
        }
        return ret;
    }

    int calculate(string s) {
        iter = 0;
        int ret = calc(s);
        return ret;
    }

    int llexNext(string& s) {
        int sz = s.length();
        while(iter < sz && s[iter] == ' ') iter++;

        if(s[iter] == '+') {
            iter++;
            return -1;
        }
        else if(s[iter] == '-'){
            iter++;
            return -2;
        }
        else if(s[iter] == '(') {
            iter++;
            return -3;
        }
        else if(s[iter] == ')') {
            iter++;
            return -4;
        }
        else{
            int ret = s[iter++] - '0';
            while(iter < sz && (s[iter] >= '0' && s[iter] <= '9')) {
                ret *= 10; ret += (s[iter] - '0');
                iter++;
            }
            return ret;
        }
    }
};