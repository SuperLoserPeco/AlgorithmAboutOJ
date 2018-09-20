#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>
#include <map>  
#include <ctime>
using namespace std;

class Solution {
public:
vector<int> nums;
map<int, int> mp;
int sz;
    Solution(vector<int> nums) {
        mp.clear();
        sz = nums.size();
        for(int i = 0; i < sz; i++) {
            this->nums.push_back(nums[i]);
            mp[nums[i]]++;
        }
        srand((unsigned)time(NULL));
    }
    
    int pick(int target) {
        int cur = rand() % mp[target] + 1;
        int index = 0;
        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            if(nums[i] == target) {
                cnt++;
                if(cnt == cur) {
                    index = i;
                    break;
                }
            }
        }
        return index;
    }
};
