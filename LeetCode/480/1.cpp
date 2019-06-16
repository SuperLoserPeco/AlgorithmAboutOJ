#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        multiset<int> win(nums.begin(), nums.begin() + k);
        vector<double> ret;
        multiset<int>::iterator mid = next(win.begin(), (int)(k / 2));

        for(int i = k; ; i++)
        {
            ret.push_back(((double)(*mid) + *prev(mid, (1 - k % 2))) / 2);
            if(i >= sz)
            {
                break;
            }
            win.insert(nums[i]);
            if(nums[i] < *mid)
            {
                --mid;
            }
            if(nums[i - k] <= *mid)
            {
                ++mid;
            }
            win.erase(win.lower_bound(nums[i - k]));
        }

        return ret;
    }
};

int main() {
    
    return 0;
}