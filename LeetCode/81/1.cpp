class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            if(nums[i] == target)
                return true;
        }
        return false;
    }
};