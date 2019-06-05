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
    map<string, bool> vis;
    bool find(string S, string sub)
    {
        if(sub.length() > S.length())
        {
            return false;
        }

        int subLength = sub.length();
        int sLength = S.length();
        int current = -1;
        for(int j = 0; j < subLength; j++)
        {
            current = S.find_first_of(sub[j], current + 1);
            if(current == -1)
            {
                return false;
            }
        }
        return true;
    }

    int numMatchingSubseq(string S, vector<string>& words) {
        int count = words.size();
        int ans = 0;
        for(int i = 0; i < count; i++)
        {
            if(vis[words[i]])
            {
                ans++;
            }
            else if(find(S, words[i]))
            {
                vis[words[i]] = true;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}