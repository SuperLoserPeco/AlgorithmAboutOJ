#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;

//[-1,0,1,2,-1,-4]
//[3,0,-2,-1,1,2]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int neg = -1, pos = -1;
        int numZero = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) numZero++;
            if(i + 1 < nums.size() && nums[i + 1] >= 0 && neg == -1) neg = i;
            if(nums[i] > 0 && pos == -1) pos = i;
        }
        if(numZero >= 3) {
            vector<int> now;
            now.push_back(0);
            now.push_back(0);
            now.push_back(0);

            ans.push_back(now);
        }
        cout << "neg = " << neg << endl;

        if(neg != -1 && pos != -1 && (pos - (neg + 1) > 0)) {
            for(int i = 0; i < neg + 1; i++) {
                if(i && (nums[i] == nums[i - 1])) continue;

                for(int j = pos; j < nums.size(); j++) {
                    if(nums[i] + nums[j] == 0) {
                        vector<int> now;
                        now.push_back(nums[i]);
                        now.push_back(0);
                        now.push_back(nums[j]);
                        ans.push_back(now);
                        break;
                    }
                }
            }
        } 

        if(pos != -1 && neg != -1) {
            for(int i = 0; i < neg + 1; i++) {
                if(i && nums[i] == nums[i - 1]) continue;
                for(int j = i + 1; j < neg + 1; j++) {
                    if(nums[i] == nums[j]) continue;
                    if(j - 1 > i && nums[j] == nums[j - 1]) continue;
                    for(int k = pos; k < nums.size(); k++) {
                        if(nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> now;
                            now.push_back(nums[i]);
                            now.push_back(nums[j]);
                            now.push_back(nums[k]);
                            ans.push_back(now);
                            break;
                        }
                    }
                }
            }
        }

        if(pos != -1 && neg != -1) {
            for(int i = pos; i < nums.size(); i++) {
                if(i && nums[i] == nums[i - 1]) continue;
                for(int j = i + 1; j < nums.size(); j++) {
                    if(nums[i] == nums[j]) continue;
                    if(j - 1 > i && nums[j] == nums[j - 1]) continue;
                    for(int k = 0; k < neg + 1; k++) {
                        if(nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> now;
                            now.push_back(nums[k]);
                            now.push_back(nums[i]);
                            now.push_back(nums[j]);
                            ans.push_back(now);
                            break;
                        }
                    }
                }
            }
        }


        if(pos != -1 && neg != -1) {
            for(int i = pos; i < nums.size(); i++) {
                if(i && nums[i] == nums[i - 1]) continue;
                for(int j = 0; j < neg + 1; j++) {
                    if(j + 1 < neg + 1) {
                        if(nums[j] == nums[j + 1] &&
                            nums[j] * 2 + nums[i] == 0) {
                                vector<int> now;
                                now.push_back(nums[j]);
                                now.push_back(nums[j]);
                                now.push_back(nums[i]);
                                ans.push_back(now);
                                break;
                            }
                    }
                }
            }
        }

        if(pos != -1 && neg != -1) {
            for(int i = 0; i < neg + 1; i++) {
                if(i && nums[i] == nums[i - 1]) continue;
                for(int j = pos; j < nums.size(); j++) {
                    if(j + 1 < nums.size()) {
                        if(nums[j] == nums[j + 1] &&
                            nums[j] * 2 + nums[i] == 0) {
                                vector<int> now;
                                now.push_back(nums[i]);
                                now.push_back(nums[j]);
                                now.push_back(nums[j]);
                                ans.push_back(now);
                                break;
                            }
                    }
                }
            }
        }
        

        return ans;
    }
};