#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

class NumArray {
public:
    vector<int> currentNums;
    vector<int> tree;
    int treeSz;

    void add(int i, int val)
    {
        while(i < treeSz)
        {
            tree[i] += val;
            i += lowbit(i);
        }
    }

    int sum(int i)
    {
        int ret = 0;
        while(i > 0)
        {
            ret += tree[i];
            i -= lowbit(i);
        }
        return ret;
    }

    int lowbit(int i)
    {
        return i & (-i);
    }

    NumArray(vector<int> nums) {
        int sz = nums.size();
        treeSz = sz + 5;
        tree.resize(treeSz, 0);
        currentNums = nums;
        for(int i = 0; i < sz; i++)
        {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int change = val - currentNums[i];
        add(i + 1, change);
        currentNums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int r = sum(j + 1);
        int l = sum(i);
        return r - l;
    }
};

int main()
{
    NumArray a({0, 1, 2});
}