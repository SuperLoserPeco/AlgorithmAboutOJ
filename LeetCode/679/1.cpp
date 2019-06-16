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
    bool judgePoint24(vector<int>& nums) {
        int total = (1 << 4) -1; 
        vector<vector<double>> dp((int)(1 << 4), vector<double>(5));
        for(int i = 0; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                int a = nums[i]; int b = nums[j];
                int mask = (1 << i) | (1 << j);
                for(int k = 0; k < 5; k++)
                {
                    dp[mask][k] = operatorWork(a, b, k);
                }
            }
        }

        int* result = new int[2];
        for(int i = 0; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                int maskA = (1 << i) | (1 << j);
                int maskB = total - maskA;
                for(int k = 0; k < 5; k++)
                {
                    for(int l = 0; l < 5; l++)
                    {
                        for(int m = 0; m < 5; m++)
                        {
                            if(isEqual(operatorWork(dp[maskA][k], dp[maskB][m], l), 24))
                            {
                                cout << maskA << "--" << k << endl;
                                cout << maskB << "--" << m << endl;
                                cout << l << endl;
                                return true;
                            }
                        }
                    }
                }

                int cnt = 0;
                for(int k = 0; k < 4; k++)
                {
                    if((1 << k) & maskB)
                    {
                        result[cnt++] = k;
                    }
                }
                for(int k = 0; k < 5; k++)
                {
                    for(int m = 0; m < 5; m++)
                    {
                        double middleware = operatorWork(dp[maskA][k], nums[result[0]], m);
                        for(int l = 0; l < 5; l++)
                        {
                            if(isEqual(operatorWork(middleware, nums[result[1]], l), 24))
                            {
                                cout << "maskA " << maskA << endl;
                                cout << "val a " << dp[maskA][k] << endl;
                                cout << "k " << k << endl;

                                cout << "num1 " << nums[result[1]] << endl;
                                cout << "m " << m << endl;

                                cout << "num2 " << nums[result[0]] << endl;
                                cout << "l " << l << endl;
                                return true;
                            }
                        }
                        
                        middleware = operatorWork(dp[maskA][k], nums[result[1]], m);
                        for(int l = 0; l < 5; l++)
                        {
                            if(isEqual(operatorWork(middleware, nums[result[0]], l), 24))
                            {
                                cout << "maskA " << maskA << endl;
                                cout << "val b " << dp[maskA][k] << endl;
                                cout << "k " << k << endl;

                                cout << "num1 " << nums[result[1]] << endl;
                                cout << "m " << m << endl;

                                cout << "num2 " << nums[result[0]] << endl;
                                cout << "l " << l << endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    bool isEqual(double a, int b)
    {
        return abs(a - (double)b) < 0.000000001;
    }

    double operatorWork(double a, double b, int op)
    {
        switch(op)
        {
            case 0:
                return a + b;
            case 1:
                return abs(a - b);
            case 2:
                return a * b;
            case 3:
                if(b == 0)
                {
                    return 0;
                }
                return a / b;
            case 4:
                if(a == 0)
                {
                    return 0;
                }
                return b / a;
            default:
                return 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> input = {1, 5, 9, 1};
    cout << s.judgePoint24(input) << endl;
    return 0;
}