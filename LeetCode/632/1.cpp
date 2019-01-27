#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int L[3];
        memset(L, 0, sizeof(L));
        int minValue = -1;
        int ansL = 0, ansR = 0;
        if(nums.size() == 1)
        {
            vector<int> ans0;
            ans0.push_back(nums[0][0]);
            ans0.push_back(nums[0][0]);
            return ans0;
        }

        if(nums.size() == 2)
        {
            vector<int> add;
            for(int i = 0; i < nums[0].size(); i++)
            {
                add.push_back(nums[0][i]);
            }
            nums.push_back(add);
        }
        int sz0 = nums[0].size();
        int sz1 = nums[1].size();
        int sz2 = nums[2].size();
        while(L[0] < sz0 && L[1] < sz1 && L[2] < sz2)
        {
            int miIdx = minIdx(L[0], L[1], L[2], nums);
            int mxIdx = maxIdx(L[0], L[1], L[2], nums);
            int mdIdx = midIdx(L[0], L[1], L[2], nums);
            int left = nums[miIdx][L[miIdx]];
            int right = nums[mxIdx][L[mxIdx]];
            if(minValue == -1 || right - left < minValue)
            {
                ansL = left;
                ansR = right;
                minValue = right - left;
            }
            if(L[miIdx] + 1 < nums[miIdx].size())
            {
                L[miIdx]++;
            }
            else if(L[mdIdx] + 1 < nums[mdIdx].size())
            {
                L[mdIdx]++;
            }
            else if(L[mxIdx] + 1 < nums[mxIdx].size())
            {
                L[mxIdx]++;
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansL);
        ans.push_back(ansR);
        return ans;
    }

    int minIdx(int l1, int l2, int l3, vector<vector<int>>& nums)
    {
        if(nums[0][l1] < nums[1][l2])
        {
            if(nums[0][l1] < nums[2][l3])
            {
                return 0;
            }
            else{
                return 2;
            }
        }
        else{
            if(nums[2][l3] < nums[1][l2])
            {
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    int maxIdx(int l1, int l2, int l3,  vector<vector<int>>& nums)
    {
        if(nums[0][l1] < nums[1][l2])
        {
            if(nums[1][l2] < nums[2][l3])
            {
                return 2;
            }
            else{
                return 1;
            }
        }
        else{
            if(nums[2][l3] < nums[0][l1])
            {
                return 0;
            }
            else{
                return 2;
            }
        }
    }

    int midIdx(int l1, int l2, int l3,  vector<vector<int>>& nums)
    {
        int _minIdx = minIdx(l1, l2, l3, nums);
        int _maxIdx = maxIdx(l1, l2, l3, nums);
        return 3 - _minIdx - _maxIdx;
    }
};