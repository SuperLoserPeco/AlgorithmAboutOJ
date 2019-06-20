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
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        bool nextExist = false;
        int locate = -1;
        for(int i = sz - 1; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                locate = i;
                nextExist = true;
                break;
            }
        }
        if(nextExist)
        {
            int upper = nums[locate + 1];
            int upperLocate = locate + 1;
            for(int i = locate + 1; i < sz; i++)
            {
                if(nums[i] < upper && nums[i] > nums[locate])
                {
                    upper = nums[i];
                    upperLocate = i;
                }
            }

            int temp = nums[locate];
            nums[locate] = nums[upperLocate];
            nums[upperLocate] = temp;

            for(int i = locate + 1; i < locate + 1 + (sz - locate - 1) / 2; i++)
            {
                int temp = nums[i];
                nums[i] = nums[sz - (i - locate - 1) - 1];
                nums[sz - (i - locate - 1) - 1] = temp;
            }
        }
        else{
            for(int i = 0; i < sz / 2; i++)
            {
                int temp = nums[i];
                nums[i] = nums[sz - i - 1];
                nums[sz - i - 1] = temp; 
            }
        }
    }
};

int main() {
    vector<int> vec={1, 2, 3};
    Solution s;
    s.nextPermutation(vec);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}