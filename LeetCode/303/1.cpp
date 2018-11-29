#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

class NumArray {
public:
    vector<int> num;
    NumArray(vector<int> nums) {
        num.push_back(0);
        for(int i = 0; i < nums.size(); i++)
        {
            num.push_back(nums[i]);
            num[i + 1] += num[i];
        }
    }
    
    int sumRange(int i, int j) {
        return num[j + 1] - num[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */