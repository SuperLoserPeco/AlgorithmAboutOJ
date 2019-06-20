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
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        for(int i = sz - 1; i >= 0; i--)
        {
            for(int j = sz - 1; j > i; j--)
            {
                if(nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;
    return 0;
}