#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    string originalDigits(string s) {
        vector<string> vec = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        map<int, int> mp;
        mp.clear();
        string ret = "";
        int sz = s.length();
        for(int i = 0; i < sz; i++)
        {
            mp[s[i] - 'a']++;
        }
        int num = vec.size();
        for(int i = 0; i < num; i++)
        {
            int digitNum = vec[i].length();
            int mx = sz + 1;
            map<int, int> mp2;
            for(int j = 0; j < digitNum; j++)
            {
                mp2[vec[i][j] - 'a']++;
            }
            for(map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
            {
                mx = min(mx, mp[it->first] / it->second);
            }
            for(int j = 0; j < mx; j++)
            {
                ret += ('0' + i);
            }
            for(map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
            {
                mp[it->first] -= (mx * it->second);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("fviefuro") << endl;
    return 0;
}