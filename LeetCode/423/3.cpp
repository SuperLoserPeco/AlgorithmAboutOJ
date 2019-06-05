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
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<char> ch{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        map<int, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i] - 'a']++;
        }
        string ret = "";
        for(int i = 0; i < words.size(); i++)
        {
            int digitCnt = mp[ch[i] - 'a'];
            for(int j = 0; j < words[i].size(); j++)
            {
                mp[words[i][j] - 'a'] -= digitCnt;
            }
            for(int j = 0; j < digitCnt ; j++)
            {
                ret += ('0' + nums[i]);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    
    return 0;
}