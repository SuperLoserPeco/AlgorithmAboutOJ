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
#include <unordered_map>
using namespace std;
typedef long long LL;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charCount(128, 0);
        vector<bool> vis(128, false);
        for(int i = 0; i < s.length(); i++)
        {
            charCount[s[i]]++;
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            charCount[s[i]]--;
            if(vis[s[i]])
            {
                continue;
            }
            while((ans.length() > 0 && s[i] < ans.back())
                    && charCount[ans.back()] > 0)
            {
                vis[ans.back()] = false;
                ans.pop_back();
            }
            ans += s[i];
            vis[s[i]] = true;
        }
        return ans;
    }
};

int main() {
    
}