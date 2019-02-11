#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int szA = A.length();
        int szB = B.length();
        if(szA != szB)
        {
            return false;
        }
        vector<int> diffNum;
        for(int i = 0; i < szA; i++)
        {
            if(A[i] != B[i])
            {
                diffNum.push_back(i);
            }
        }
        if(diffNum.size() == 0)
        {
            bool vis[26];
            memset(vis, false, sizeof(vis));
            for(int i = 0; i < szA; i++)
            {
                if(vis[A[i] - 'a'])
                {
                    return true;
                }
                vis[A[i] - 'a'] = true;
            }
            return false;
        }
        else  if(diffNum.size() != 2)
        {
            return false;
        }
        else{
            return A[diffNum[0]] == B[diffNum[1]] &&
                    A[diffNum[1]] == B[diffNum[0]];
        }
    }
};