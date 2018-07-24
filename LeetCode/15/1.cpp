#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());
        int n = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != 0 && nums[i] == nums[i - 1]) {
                n++;
                if(n > 2) {
                    nums.erase(nums.begin() + i);
                    n--; i--;
                }
            }
            else {
                n = 1;
            }
        }
        int sz = nums.size();
        for(int i = 0; i < sz; i++)
        cout << nums[i] << endl;
        int iter = 0;
        while(nums[iter] < 0 && iter < sz) iter++;
        int neg = iter;
        while(nums[iter] == 0 && iter < sz) iter++;
        int zero = iter;
        for(int i = 0; i < neg; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < neg; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                for(int k = zero; k < sz; k++) {
                    if(k > zero && nums[k] == nums[k - 1]) continue;
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ret.push_back(ans);
                    }
                }
            }
        }
        for(int i = 0; i < neg; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = zero; j < sz; j++) {
                if(j > zero && nums[j] == nums[j - 1]) continue;
                for(int k = j + 1; k < sz; k++) {
                    if(k > j + 1 && nums[k] == nums[k - 1]) continue;
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ret.push_back(ans);
                    }
                }
            }
        }
        if(zero - neg > 0) {
            for(int i = 0; i < neg; i++) {
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                for(int j = zero; j < sz; j++) {
                    if(j > zero && nums[j] == nums[j - 1]) continue;
                    if(nums[i] + nums[j] == 0) {     
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(0);
                        ans.push_back(nums[j]);
                        ret.push_back(ans);
                    }
                }
            }
        }
        if(zero - neg >= 3) {
            vector<int> ans;
            ans.push_back(0);
            ans.push_back(0);
            ans.push_back(0);
            ret.push_back(ans);
        }
        return ret;
    }
};