#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    struct heightInfo {
        int i;
        int height;
    };
    vector<heightInfo> l;
    vector<heightInfo> r;

    int maxArea(vector<int>& height) {
        int sz = height.size();
        int last = 0;
        for(int i = 0; i < sz; i++) {
            heightInfo info;
            info.i = i;
            info.height = height[i];
            if(!i || info.height > last) {
                l.push_back(info);
                last = height[i];
            }
        }
        last = 0;
        for(int i = sz - 1; i >= 0; i--) {
            heightInfo info;
            info.i = i;
            info.height = height[i];
            if(i == sz - 1 || info.height > last) {
                r.push_back(info);
                last = info.height;
            }
        }
        int lsz = l.size();
        int rsz = r.size();
        int ans = 0;
        for(int i = 0; i < lsz; i++)
        for(int j = 0; j < rsz; j++) {
            if(l[i].i >= r[j].i)
                break;
            ans = max(ans, min(l[i].height, r[j].height) * (r[j].i - l[i].i));
        }
        return ans;
    }
};