#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while(i < sz1 && j < sz2) {
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else {
                int sz = ans.size();
                if(!(sz > 0 && ans[sz - 1] == nums1[i])) ans.push_back(nums1[i]);
                i++; j++;
            }
        }
        return ans;
    }
};