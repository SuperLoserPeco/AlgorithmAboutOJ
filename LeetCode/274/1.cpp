#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int sz = citations.size();
        if(sz == 0) return 0;
        if(sz == 1) return (citations[0] != 0);
        
        for(int i = 1; i < sz; i++) {
            int h = sz - i;
            if(citations[i - 1] <= h && citations[i] >= h) {
                return h;
            }
        }
        if(sz <= citations[0]) return sz;
        return 0;
    }
};