#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            if(nums[i] == target)
                return i + 1;
        }
        return -1;
    }
};