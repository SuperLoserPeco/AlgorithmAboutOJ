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

typedef long long LL;

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int maxNum = 15;
        int* dp = new int[maxNum];
        dp[0] = 1;
        dp[1] = 9;
        for(int i = 2; i <= 10; i++)
        {
            dp[i] = 9 * A(9, (i - 1));
            dp[i] += dp[i - 1];
            // cout << i << " --- " << dp[i] << endl;
        }

        int* num = new int[maxNum];
        int cur = N;
        int cnt = 0;
        while(cur)
        {
            num[cnt++] = cur % 10;
            cur /= 10;
        }
        reverse(num, num + cnt);
        int ans = 0;

        map<int, int> mp;
        if(cnt == 1)
        {
            return 0;
        }
        ans += dp[cnt - 1];
        for(int i = 0; i < cnt; i++)
        {
            int currentVal = num[i];
            // if(currentVal > 0)
            // {
            //     if(!mp[0])
            //     {
            //         ans += dp[cnt - i - 1];
            //     }
            // }
            int start = i == 0 ? 1 : 0;
            for(int j = start; j < currentVal; j++)
            {
                if(mp[j])
                {
                    continue;
                }
                ans += (A(10 - i - 1, cnt - i - 1));
            }

            if(mp[currentVal])
            {
                break;
            }
            else{
                mp[currentVal] = true;
                if(i == cnt - 1)
                {
                    ans++;
                }
            }
        }

        return N - ans;        
    }

    int A(int a, int b)
    {
        int ret = 1;
        for(int i = a; i > a - b; i--)
        {
            ret *= i;
        }
        return ret;
    }
};

int main() {
    Solution s;
    // int param1 = 20;
    int param1;
    cin >> param1;
    int ans = s.numDupDigitsAtMostN(param1);
    cout << "result : " << ans << endl;
    return 0;
}