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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        int len = nums.size();
        if(len == 0)
        {
            return vec;
        }

        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++)
        {
            if(i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            unordered_map<int, int> _map;
            for(int j = i + 1; j < len; j++)
            {
                if(_map.find(-nums[i] - nums[j]) != _map.end())
                {
                    vec.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                    while(j + 1 < len && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                }
                _map.insert({nums[j], j});
            }

        }
        return vec;
    }
};