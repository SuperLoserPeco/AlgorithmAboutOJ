#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    map<int, bool> mp;
    bool isHappy(int n) {
        int cur = n;
        while(cur != 1) {
            if(mp[cur]) return false;
            mp[cur] = true;
            int temp = cur;
            cur = 0;
            while(temp > 0) {
                cur += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            cout << cur << endl;
        }
        return true;
    }
};