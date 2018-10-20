#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int cnt = 1;
        for(int i = 2; i <= n * 2; i++)
        {
            int cur = i;
            while(cur % 2 == 0) cur /= 2;
            while(cur % 3 == 0) cur /= 3;
            while(cur % 5 == 0) cur /= 5;
            if(cur == 1)
            {
                cnt++;
                if(cnt == n)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};