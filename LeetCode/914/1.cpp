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
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        int sz = deck.size();
        for(int i = 0; i < sz; i++) {
            mp[deck[i]]++;
        }

        int mi = INT_MAX;
        vector<int> temp;
        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            temp.push_back(iter->second);
            mi = min(mi, iter->second);
        }
        int sz2 = temp.size();
        int result = temp[0];
        for(int i = 1; i < sz2; i++) {
            result = gcd(result, temp[i]);
        }
        return result >= 2;
    }
};