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
using namespace std;

typedef long long LL;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int last = -2;
        int enabled = 0;
        for(int i = 0; i < sz; i++)
        {
            int current = flowerbed[i];
            if(current == 1)
            {
                if(i - last > 2)
                {
                    enabled += (i - last - 2) / 2;
                }
                last = i;
            }
        }
        if(sz - last > 2)
        {
            enabled += (sz - last - 1) / 2;
        }
        return enabled >= n;
    }
};

int main() {
    
    return 0;
}