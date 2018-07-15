class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        vector<int> left, right, ret;
        left.push_back(1);
        right.push_back(1);
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            int mulLeft = left[i] * nums[i];
            left.push_back(mulLeft);
            int mulRight = right[i] * nums[sz - i - 1];
            right.push_back(mulRight);
        }
        left.push_back(1); right.push_back(1);
        reverse(right.begin(), right.end());
        for(int i = 1; i <= sz; i++) {
            ret.push_back(left[i - 1] * right[i + 1]);
        }
        return ret;
    }
};