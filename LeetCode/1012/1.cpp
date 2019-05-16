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
        int maxNum = 35;
        int* dp = new int[maxNum];
        dp[0] = 0;
        for(int i = 1; i <= 10; i++)
        {
            dp[i] = 9 * C1(0, (i - 1));
            dp[i] += dp[i - 1];
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
        int ans = dp[cnt - 1];

        map<int, int> mp;
        if(cnt == 1)
        {
            return 0;
        }
        for(int i = 0; i < cnt; i++)
        {
            int currentVal = num[i];
            if(currentVal > 0)
            {
                if(!mp[0] && i != 0)
                {
                    ans += C1(i, cnt - i - 1);
                }
            }
            for(int j = 1; j < currentVal; j++)
            {
                if(mp[j])
                {
                    continue;
                }
                ans += C2(i + 1, cnt - i - 1);
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

    int C1(int a, int b)
    {
        int ret = 1;
        for(int i = 9 - a; i > 9 - a - b; i--)
        {
            ret *= i;
        }
        return ret;
    }

    int C2(int a, int b)
    {
        int ret = 1;
        for(int i = 10 - a; i > 10 - a - b; i--)
        {
            ret *= i;
        }
        return ret;
    }
};

int main() {
    Solution s;
    int current;
    scanf("%d", &current);
    printf("%d\n", s.numDupDigitsAtMostN(current));
    return 0;
}