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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        {
            sum += nums[i];
        }

        if(sum % 2 == 1)
        {
            return false;
        }

        int part = sum / 2;
        int* bag = new int[part + 1];
        bag[0] = 1;
        for(int i = 0; i < sz; i++)
        {
            for(int j = part; j >= nums[i]; j--)
            {
                if(bag[j - nums[i]] == 1)
                {
                    bag[j] = 1;
                }
            }
        }
        return bag[part] == 1;
    }
};

int main() {
    
    return 0;
}