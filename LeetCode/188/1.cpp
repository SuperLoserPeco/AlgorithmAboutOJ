#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>

#include <sstream>
using namespace std;


//https://blog.csdn.net/Bendaai/article/details/81144338
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        // if(prices.empty() || k == 0) return 0;

        // vector<int> P;
        // int l = prices[0], r = 0, xx = 0;
        // int sz = prices.size();
        // for(int i = 1; i < sz; i++) {
        //     if(prices[i] < r) {
        //         P.push_back(l);
        //         P.push_back(r);
        //         xx += (r - 1);
        //         l = prices[i];
        //         r = 0;
        //     }
        //     else {
        //         l = min(l, prices[i]);
        //         r = max(r, prices[i]);
        //     }
        // }
        // if(r) {
        //     P.push_back(l);
        //     P.push_back(r);
        //     xx += (r - 1);
        // }
        // if(Q.empty()) return 0;
    }
};