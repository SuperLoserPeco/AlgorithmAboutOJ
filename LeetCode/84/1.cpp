
#include <vector>
using namespace std;


class Solution {
public:
    int prev[100000];
    int next[100000];
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        prev[1] = 0;
        next[sz] = sz + 1;
        for(int i = 1; i < sz; i++) {
            int left = i;
            while(left > 0 && heights[i] <= heights[left - 1])
                left = prev[left];
            prev[i + 1] = left;
        }
        for(int i = sz - 2; i >= 0; i--) {
            int right = i + 2;
            while(right <= sz && heights[i] <= heights[right - 1])
                right = next[right];
            next[i + 1] = right;
        }
        int ans = 0;
        for(int i = 1; i <= sz; i++) {
            ans = max(ans, (next[i] - prev[i] - 1) * heights[i - 1]);
        }
        return ans;
    }
};