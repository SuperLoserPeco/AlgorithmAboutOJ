#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int ret = 1;
        int cur = 1;
        for(int i = 1; i < sz; i++) {
            if(nums[i] == nums[i - 1]) {
                if(cur < 2) {
                    nums[ret] = nums[i];
                    cur++;
                    ret++;
                }
            }
            else {
                nums[ret] = nums[i];
                cur = 1;
                ret++;
            }
        }
        return ret;
    }
};