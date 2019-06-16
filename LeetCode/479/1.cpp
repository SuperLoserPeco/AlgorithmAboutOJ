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
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        LL l = pow(10, n - 1);
        LL r = pow(10, n) - 1;
        for(LL i = r; i > l; i--)
        {
            LL pa = getPalindrome(i);
            for(LL j = r; j * j >= pa; j--)
            {
                if(pa % j == 0)
                {
                    return pa % 1337;
                }
            }
        }
        return 0;
    }

    LL getPalindrome(int num)
    {
        string s1 = to_string(num);
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        s2 = s2 + s1;
        return atoll(s2.c_str());
    }
};

int main() {
    
    return 0;
}