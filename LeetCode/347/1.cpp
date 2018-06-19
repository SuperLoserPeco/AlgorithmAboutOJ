#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    struct State {
        int l, r;
        int val;
        bool operator < (const State& rhs) {
            return (r - l) > (rhs.r - rhs.l);
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<State> vecState;
        int sz = nums.size();
        int l = 0, r = 0;
        for(int i = 0; i < sz; i++) {
            r = i;
            if(i + 1 >= sz || nums[i + 1] != nums[i]) {
                State st;
                st.l = l; st.r = r; st.val = nums[i];
                l = i + 1;
                vecState.push_back(st);
            }
        }
        sort(vecState.begin(), vecState.end());
        vector<int> ret;
        for(int i = 0; i < min(k, sz); i++)
            ret.push_back(vecState[i].val);
        return ret;
    }
};