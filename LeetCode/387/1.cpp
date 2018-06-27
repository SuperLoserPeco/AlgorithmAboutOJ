#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        int sz = s.length();
        for(int i = 0; i < sz; i++){
            mp[s[i]]++;
        }
        for(int i = 0; i < sz; i++) {
            if(mp[s[i]] == 1)
            return i;
        }
        return -1;
    }
};