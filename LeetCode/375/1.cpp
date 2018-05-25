#include <vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        int l = 1, r = n;
        int ret = 0;
        while(l < r) {
            ret = ret + (l + r) / 2;
            l = (l + r) / 2 + 1;
        }
        return ret;
    }
};