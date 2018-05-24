#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        int preZero = 0;

        int ret = nums[0];
        for(int i = 0; i < sz; i++)
            ret = max(ret, nums[i]);
        for(int i = 0; i < sz; i++) {
            if(nums[i] == 0) {
                if(i == preZero) {
                    //do nothing
                }
                else{
                    int l = preZero, r = i + 1;
                    
                    preZero = i + 1;
                }
            }
        }
    }
};