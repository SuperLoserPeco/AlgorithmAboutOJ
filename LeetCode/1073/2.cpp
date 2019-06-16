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
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        int sz1 = arr1.size();
        int sz2 = arr2.size();
        int last = 0;
        int mx = max(sz1, sz2);
        vector<int> arrResult;
        for(int i = 0; i < mx; i++)
        {
            int now = last;
            if(i < sz1)
            {
                now += arr1[i];
            }
            if(i < sz2)
            {
                now += arr2[i];
            }
            if(now == -1)
            {
                now = 1;
                arrResult.push_back(now % 2);
                last = 1;
            }
            else{
                arrResult.push_back(now % 2);
                last = -(now / 2);
            }
        }   
        if(last != 0)
        {
            if(last == -1)
            {
                arrResult.push_back(1);
                arrResult.push_back(1);
            }
            else{
                arrResult.push_back(1);
            }
        }
        
        while(arrResult.size() > 1)
        {
            if(arrResult.back() == 0)
            {
                arrResult.pop_back();
            }
            else{
                break;
            }
        }

        reverse(arrResult.begin(), arrResult.end());
        if(arrResult.size() == 0)
        {
            arrResult.push_back(0);
        }
        return arrResult;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {1,1,1,1,1};
    vector<int> arr2 = {1, 0, 1};
    s.addNegabinary(arr1, arr2);
    return 0;
}