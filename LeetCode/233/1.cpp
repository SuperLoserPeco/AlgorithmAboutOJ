#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int* num = new int[30];
        num[0] = 1;
        for(int i = 1; i <= 20; i++)
            num[i] = num[i - 1] * 10;
        int* dp = new int[30];
        dp[0] = 1;

        for(int i = 1; i <= 20; i++) {
            dp[i] = 10 * dp[i - 1] + num[i];
        }      
    }
};