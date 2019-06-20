#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    int myAtoi(string str) {
        LL mxNeg = 2147483648;

        int sz = str.length();

        int currentFlag = 0;
        bool isPositive = true;
        LL currentNum = 0;
        bool isFlagExist = false;
        
        for(int i = 0; i < sz; i++)
        {
            if(isAlpha(str[i]))
            {
                if(currentFlag == 0)
                {
                    return 0;
                }
                else{
                    if(currentFlag == 1)
                    {
                        currentFlag = 2;
                    }
                    continue;
                }
            }
            if(isDigit(str[i]))
            {
                if(currentFlag == 0)
                {
                    currentFlag = 1;
                }

                if(currentFlag == 1)
                {
                    if(currentNum > (LL)mxNeg)
                    {
                        currentFlag = 2;
                        continue;
                    }
                    currentNum *= 10;
                    currentNum += (str[i] - '0');
                }
            }
            if(isBlank(str[i]))
            {
                if(currentFlag == 1)
                {
                    currentFlag = 2;
                    continue;
                }
                else if(currentFlag == 0 && isFlagExist)
                {
                    return 0;
                }
            }
            if(isNeg(str[i]))
            {
                if(currentFlag == 0)
                {
                    if(isFlagExist)
                    {
                        return 0;
                    }
                    else{
                        isFlagExist = true;
                    }
                    isPositive = !isPositive;
                }
                else if(currentFlag == 1)
                {
                    currentFlag = 2;
                }
            }
            if(isPos(str[i]))
            {
                if(currentFlag == 0)
                {
                    if(isFlagExist)
                    {
                        return 0;
                    }
                    else{
                        isFlagExist = true;
                    }
                }
                else if(currentFlag == 1)
                {
                    currentFlag = 2;
                }
            }
            if(isDot(str[i]))
            {
                if(currentFlag == 0)
                {
                    return 0;
                }
                else if(currentFlag == 1)
                {
                    currentFlag = 2;
                }
            }
        }
        if(!isPositive)
        {
            if(currentNum > 2147483648)
            {
                return -2147483648;
            }
            else{
                return -currentNum;
            }
        }
        else{
            if(currentNum > 2147483647)
            {
                return 2147483647;
            }
            else{
                return currentNum;
            }
        }
    }
    bool isDot(char ch)
    {
        return ch == '.';
    }
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool isBlank(char ch)
    {
        return ch == ' ';
    }
    bool isAlpha(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }
    bool isNeg(char ch)
    {
        return ch == '-';
    }
    bool isPos(char ch)
    {
        return ch == '+';
    }
};

int main() {
    Solution s;
    // cout << s.myAtoi("4193 with words") << endl;
    cout << s.myAtoi("-   234") << endl;
    return 0;
}