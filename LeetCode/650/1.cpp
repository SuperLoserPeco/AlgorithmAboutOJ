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
    int minSteps(int n) {
        int current = n;
        int cnt = 0;
        for(int i = 2; i * i < n; i++)
        {
            while(current % i == 0)
            {
                cnt++;
                current /= i;
            }
        }
        cnt+=(current - 1);
        return cnt;
    }
};