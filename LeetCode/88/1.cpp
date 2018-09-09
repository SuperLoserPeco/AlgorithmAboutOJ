#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            nums1.insert(nums1.begin() + m, nums2[i]);
        }
        sort(nums1.begin(), nums1.begin() + m + n);
        nums1.erase(nums1.begin() + (m + n), nums1.end());
        
    }
};