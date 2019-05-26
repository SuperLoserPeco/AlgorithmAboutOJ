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
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int sz = stones.size();
        for(int i = 0; i < sz; i++)
        {
            sum += stones[i];
        }
        int part = sum / 2;
        int* bag = new int[part + 1];
        for(int i = 0; i < part + 1; i++)
        {
            bag[i] = 0;
        }
        for(int i = 0; i < sz; i++)
        {
            for(int j = part; j >= stones[i]; j--)
            {
                bag[j] = max(bag[j], bag[j - stones[i]] + stones[i]);
            }
        }
        return abs(sum - 2 * bag[part]);
    }
};

int main() {
    
    return 0;
}