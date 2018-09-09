#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int num = n;
        int num1 = 0;
        int num0 = 0;
        if(num == -2147483648) return false;
        else if(num <= 0) return false;
        while(num) {
            ((num % 3) > 0) ? num1 += (num % 3) :num0++;
            num /= 3;
        }
        return num1 <= 1;
    }
};