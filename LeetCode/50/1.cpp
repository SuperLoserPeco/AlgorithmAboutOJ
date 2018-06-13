class Solution {
public:
    double myPow(double x, int n) {
        double factor = n > 0 ? x : 1 / x;
        long long longn = n;
        //居然是精度的问题
        longn = longn > 0 ? longn : -longn;
        double ans = 1.0;
        while(longn) {
            if(longn & 1) {
                ans = ans * factor;
            }
            factor = factor * factor;
            longn >>= 1;
        }
        return ans; 
    }
};