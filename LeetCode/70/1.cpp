#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;

        int last2 = 1, last1 = 2;
        int now;
        for(int i = 3; i <= n; i++) {
            now = last2 + last1;
            last2 = last1;
            last1 = now;
        }
        return now;
    }
};