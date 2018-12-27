#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
class Solution {
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    int nthMagicalNumber(int N, int A, int B) {
        LL low = 0, high = 2000000000000000000L;
        int g = A * B / gcd(A, B);
        while(low < high)
        {
            LL mid = (low + high) / 2;
            LL t = mid / A + mid / B - mid /g;
            if(t < N) {
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return (int)(high % mod);
    }
};