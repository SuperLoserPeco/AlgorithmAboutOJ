#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();

        vector<vector<int>> ret;

        for(int i = 0; i < sz; i++)
        for(int j = i + 1; j < sz; j++) {
            int l1 = j + 1;
            int l2 = l1 + 1;
            int cur = nums[i] + nums[j];
            while(cur + nums[l1] + nums[l2] != k) {
                if(l1 >= l2) break;
                if(l1 >= sz || l2 >= sz) break;

                if(cur + nums[l1] + nums[l2] < k) {
                    if(l2 < sz) l2++;
                    else l1++;
                }
                else if(cur + nums[l1] + nums[l2] == k) {
                    
                }
            }
        }
    }
};