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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        int _size = nums.size();
        if(_size == 0 || k > _size)
        {
            return vec;
        }
        deque<int> Q;
        for(int i = 0; i < _size; i++)
        {
            if(!Q.empty())
            {
                if(i >= Q.front() + k)
                {
                    Q.pop_front();
                }
                while(!Q.empty() && nums[i] >= nums[Q.back()])
                {
                    Q.pop_back();
                }
            }
            Q.push_back(i);
            if(i + 1 >= k)
            {
                vec.push_back(nums[Q.front()]);
            }
        }
        return vec;
    }
};