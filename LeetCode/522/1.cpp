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
    bool isSame(string a, string b)
    {
        int i = 0, j = 0;
        while(i < a.length() && j < b.length())
        {
            if(a[i] == b[j])
            {
                i++; j++;
            }
            else{
                j++;
            }
        }
        return i == a.length();
    }

    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int sz = strs.size();
        for(int i = 0; i < sz; i++)
        {
            bool isExist = false;
            for(int j = 0; j < sz; j++)
            {
                if(i != j && isSame(strs[i], strs[j]))
                {
                    isExist = true;
                    break;
                }
            }
            if(!isExist)
            {
                ans = max(ans, (int)strs[i].length());
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}