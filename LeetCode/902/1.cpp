#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> num;
        for(int i = 0; i < D.size(); i++)
        {
            num.push_back(D[i][0] - '0');
        }
        if(num.size() == 0)
        {
            return 0;
        }
        int cnt = 0;
        int temp = N;
        while(temp > 0)
        {
            temp /= 10;
            cnt++;
        }
        cout << temp;
        int* dp = new int[cnt+1];
        int* digit = new int[cnt + 1];
        int count = D.size();
        dp[0] = 1;
        for(int i = 1; i <= cnt; i++)
        {
            dp[i] = dp[i - 1] * count;
        }

        temp = N;
        for(int i = cnt; i >= 1; i--)
        {
            digit[i] = temp % 10;
            temp /= 10;
        }
        int ans = 0;
        for(int i = 1; i < cnt; i++)
        {
            ans += dp[i];
        }
        for(int i = 1; i <= cnt; i++)
        {
            int litter = 0;
            int sz = num.size();
            for(int j = 0; j < sz; j++)
            {
                if(num[j] < digit[i])
                {
                    litter++;
                }
            }
            ans += (litter * dp[cnt - i]);

            bool eqExist = false;
            for(int j = 0; j < sz; j++)
            {
                if(num[j] == digit[i])
                {
                    eqExist = true;
                    break;
                }
            }
            if(!eqExist)
            {
                break;
            }
            else if(i == cnt)
            {
                ans++;
            }
        }

        return ans;
    }
};