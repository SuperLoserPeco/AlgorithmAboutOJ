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

//https://www.cnblogs.com/Doctengineer/p/5814665.html KSUM

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }
            if(nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
            {
                continue;
            }
            for(int j = i + 1; j < n - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while(left < right)
                {
                    if(nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do{
                            left++;
                        }while(left < right && nums[left] == nums[left-1]);
                        do{
                            right--;
                        }while(left < right && nums[right] == nums[right + 1]);
                    }
                }
            }
        }
        return res;
    }
};