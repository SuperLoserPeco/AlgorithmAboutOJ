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
        int digitNum = vec.size();
        map<int, int> digitNumCount;
        while(sz > 0)
        {
            bool isOK = false;
            for(int i = 0; i < digitNum; i++)
            {
                map<int, int> mp2;
                for(int j = 0; j < vec[i].length(); j++)
                {
                    mp2[vec[i][j] - 'a']++;
                }
                bool exist = true;
                for(map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
                {
                    if(it->second > mp[it->first])
                    {
                        exist = false;
                        break;
                    }
                }
                if(exist)
                {
                    isOK = true;
                    digitNumCount[i]++;
                    for(map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
                    {
                        mp[it->first] -= it->second;
                        sz -= it->second;
                    }
                }
            }
            if(!isOK)
            {
                break;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < digitNumCount[i]; j++)
            {
                ret += ('0' + i);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
    return 0;
}