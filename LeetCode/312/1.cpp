#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <set>

#include <algorithm>
using namespace std;

typedef long long LL;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return nums[0] * nums[1] + max(nums[0], nums[1]);
        }
        int sz = nums.size();
        int* dp = new int[sz + 2];
        dp[0] = dp[sz + 1] = 1;
        int* valLeft = new int[sz + 2];
        int* valRight = new int[sz + 2];
        valLeft[0] = valRight[0] = 0;
        valLeft[sz + 1] = valRight[sz + 1] = sz + 1;
        set<pair<int, int>> pa;
        set<pair<int, int>> paLocate;
        for(int i = 1; i <= sz; i++)
        {
            pa.insert(make_pair(nums[i - 1], i));
            dp[i] = nums[i - 1];
            valLeft[i] = i - 1;
            valRight[i] = i + 1;
        }
        int ans = 0;
        int count = 0;
        set<pair<int, int>>::iterator it;
        for(it = pa.begin(); it != pa.end(); it++)
        {
            if(sz - count > 3) {
                count++;
            }
            else{
                paLocate.insert(make_pair(it->second, it->first));
                count++;
                continue;
            }
            pair<int, int> current = *it;
            int leftIdx = valLeft[current.second];
            int rightIdx = valRight[current.second];
            cout << current.first << " " << dp[leftIdx] << " " << dp[rightIdx] << endl;
            ans += (current.first * dp[leftIdx] * dp[rightIdx]);
            if(rightIdx != sz + 1) {
                valLeft[rightIdx] = leftIdx;
            }
            if(leftIdx != 0) {
                valRight[leftIdx] = rightIdx;
            }
        }
        it = paLocate.begin();
        if(it != paLocate.end()) {
            int valRestLeft = it->second; it++;
            int valRestMid = it->second; it++;
            int valRestRight = it->second;
            cout << valRestLeft << " " << valRestMid << " " << valRestRight << endl;
            int ansA = 0;
            ansA +=( valRestLeft * valRestMid * valRestRight);
            ansA += (valRestLeft * valRestRight);
            ansA += (max(valRestLeft, valRestRight));

            int ansB = 0;
            ansB += (valRestLeft * valRestMid);
            ansB += (valRestRight * valRestMid);
            ansB += (max(valRestRight, valRestMid));

            int ansC = 0;
            ansC += (valRestLeft * valRestMid);
            ansC += (valRestRight * valRestMid);
            ansC += (max(valRestLeft, valRestMid));
            ans += (max(ansA, max(ansB, ansC)));
        }
        return ans;
    }
};