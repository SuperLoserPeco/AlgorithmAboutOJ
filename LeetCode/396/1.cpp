#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sz = A.size();
        int* dp = new int[sz + 1];
        dp[sz] = 0;
        for(int i = sz - 1; i >= 0; i--) {

        }

        int cur = 0, sum = 0;
        for(int i = 0; i < sz; i++) {
            cur = cur + (i * A[i]);
            sum = sum + A[i];
        }
        int max_val = cur;
        for(int i = 1; i < sz; i++) {
            cur = cur + sum;
            cur = cur - sz * (A[sz - i]);
            max_val = max(max_val, cur);
        }
        return max_val;
    }
};