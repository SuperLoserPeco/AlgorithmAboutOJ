#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef  long long LL;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        LL leftValue = nums[0];
        LL rightValue = nums[0];
        for(int i = 1; i < sz; i++)
        {
            leftValue = max(leftValue, (LL)nums[i]);
            rightValue += (LL)nums[i];
        }
        if(sz == 1)
        {
            return rightValue;
        }
        if(sz == m)
        {
            return leftValue;
        }

        while(leftValue < rightValue)
        {
            LL mid = (leftValue + rightValue) / 2;
            int cnt = 1; LL partsum = 0;
            for(int i = 0; i < sz; i++)
            {
                partsum += (LL)nums[i];
                if(partsum > mid)
                {
                    ++cnt;
                    partsum = (LL)nums[i];
                    if(cnt > m)
                    {
                        break;
                    }
                }
            }
            if(cnt > m)
            {
                leftValue = mid + 1;
            }
            else{
                rightValue = mid;
            }
        }
        return (int)leftValue;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2147483647};
    int m = 2;
    cout << s.splitArray(nums, m) << endl;
    return 0;
}