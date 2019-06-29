#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int cnt = 0;
        int temp = num;
        if(temp == 0)
        {
            cnt = 1;
        }
        else{
            while(temp)
            {
                temp >>= 1;
                cnt++;
            }
        }
        temp = num;
        int* digit = new int[cnt];
        for(int i = 0; i < cnt; i++)
        {
            digit[i] = temp & 1;
            temp >>= 1;
        }

        vector<vector<int>> dp(cnt, vector<int>(2));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < cnt; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }

        int ans = 0;
        int lastBit = 0;
        for(int i = cnt - 1; i >= 0; i--)
        {
            if(lastBit == 1)
            {
                if(i)
                {
                    if(digit[i] == 1)
                    {
                        ans += dp[i][0];
                        break;
                    }
                }
                else{
                    ans++;
                }
            }
            else{
                if(i)
                {
                    if(digit[i] == 1)
                    {
                        ans += dp[i][0];
                    }
                }
                else{
                    ans++;
                    ans += digit[i];
                }
            }

            lastBit = digit[i];
        }
        return ans;
    }
};

int main() {
    int param;
    cin >> param;
    Solution s;
    cout << s.findIntegers(param) << endl;
    return 0;
}