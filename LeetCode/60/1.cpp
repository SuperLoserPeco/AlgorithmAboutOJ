#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int* dp = new int[n];
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] * (n - i);
        }
        vector<int> vec;
        for(int i = 1; i <= n; i++) vec.push_back(i);
        int ret = 0; int cur = k - 1;
        for(int i = 1; i < n; i++) {
            ret *= 10;
            ret += vec[cur / dp[i]];
            vec.erase(vec.begin() + (cur / dp[i]));
            cur = cur % dp[i];
        }
        ret *= 10;
        ret += vec[0];
        return std::to_string(ret);
    }
};