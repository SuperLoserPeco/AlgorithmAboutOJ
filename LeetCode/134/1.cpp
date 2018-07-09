#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        int* dp = new int[sz + 1];

        dp[0] = gas[0];
        bool flag = true;
        for(int i = 1; i < sz; i++) {
            if(dp[i - 1] - cost[i - 1] < 0) flag = false;
            dp[i] = dp[i - 1] - cost[i - 1] + gas[i];
        }
    }
};