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
    int singleNonDuplicate(vector<int>& nums) {
        int cur = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            cur ^= nums[i];
        }
        return cur;
    }
};

int main() {
    
    return 0;
}