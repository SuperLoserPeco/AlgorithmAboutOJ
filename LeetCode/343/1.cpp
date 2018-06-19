#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int ret = 1;
        for(int i = 2; i < n; i++) {
            int m = n % i;
            int cur = 1;
            for(int j = 1; j <= (i - m); j++)
                cur = cur * (n / i);
            for(int j = 1; j <= m; j++)
                cur = cur * (n / i + 1);
            ret = max(ret, cur);
        }
        return ret;
    }
};