#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>

#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        map<int, int> mp;
        vector<int> vec;
        int sz = A.size();
        int mi = A[0];
        int ans = sz;
        for(int i = 0; i < sz; i++) {
            mp[A[i]]++;
            if(mp[A[i]] == 1) {
                vec.push_back(A[i]);
            }
            mi = min(mi, A[i]);
        }

        sort(vec.begin(), vec.end());

        int mx = A[0];
        for(int i = 0; i < sz; i++) {
            mp[A[i]] --;
            mx = max(A[i], mx);

            if(mp[A[i]] == 0) {
                vector<int>::iterator iter = find(vec.begin(), vec.end(), A[i]);
                if(iter != vec.end()) vec.erase(iter);
            }
            
            if(vec.size() == 0) {
                break;
            }
            if(mx <= vec[0]) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};