///https://blog.csdn.net/qq_17550379/article/details/85070792
#include <vector>
#include <string>
#include <iostream>
#include <map>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;


class Solution {
public:
    map<int, int> mp;
    int tallestBillboard(vector<int>& rods) {
        mp.clear();
        mp[0] = 0;
        int count = rods.size();
        for(int i = 0; i < count; i++)
        {
            int current = rods[i];
            map<int, int> mp2;
            for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                mp2[it->first] = it->second;
            }
            for(map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
            {
                
                //mem[d + i] = max(mem.get(i + d, 0), val)
                //mem[abs(d - i)] = max(mem.get(abs(d - i), 0), val + min(i, d))
                
                mp[it->first + current] = max(it->second, mp[it->first + current]);
                mp[abs(it->first - current)] = max(it->second + min(it->first, current), mp[abs(it->first - current)]);
            }
        }
        return mp[0];
    }
};