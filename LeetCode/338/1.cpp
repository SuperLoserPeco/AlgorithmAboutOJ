#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0; i <= num; i++) {
            ret.push_back(get2num(i));
        }
        return ret;
    }

    int get2num(int num) {
        int ret = 0;
        while(num > 0) {
            ret += (num & 1);
            num >>= 1;
        }
        return ret;
    }
};