#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <queue>

#include <vector>

#include <algorithm>
using namespace std;



class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int mx = A[0];
        int cur = A[0];
        int sz = A.size();
        int l = 0, r = 0;
        while(l < sz * 2 && r < sz * 2 - 1)
        {
            if(r >= sz * 2 - 1)
            {
                if(l < sz * 2)
                {
                    cur -= A[l % sz];
                    l++;

                    mx = max(mx, cur);
                }
            }
            else if(r - l + 1 < sz)
            {
                while(cur <= 0 && l <= r)
                {
                    cur -= A[l % sz];
                    l++;
                }
                r++;
                cur += A[r % sz];
                while(l < r && A[l % sz] < 0)
                {
                    cur -= A[l % sz];
                    l++;
                }

                mx = max(mx, cur);
            }
            else {
                cur -= A[l % sz];
                l++;

                mx = max(mx, cur);
            }
        }
        return mx;
    }
};