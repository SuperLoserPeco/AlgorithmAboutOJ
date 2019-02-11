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
    int addDigits(int num) {
        int nextNum = digitNumSum(num);
        while(nextNum != num)
        {
            num = nextNum;
            nextNum = digitNumSum(num);
        }
        return num;
    }

    int digitNumSum(int num)
    {
        int ret = 0;
        while(num > 0)
        {
            ret += (num % 10);
            num /= 10;
        }
        return ret;
    }
};