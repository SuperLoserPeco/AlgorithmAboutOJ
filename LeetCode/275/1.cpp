#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

//log(n) 算法 实现
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();


        int l = 1, r = sz;
        while(l < r) {
            int md = (l + r) / 2;

            
        }
    }
};