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

int* Rank;
unsigned long long* Hash;
unsigned long long* H;
unsigned long long* Xp;
class Solution {
public:
    string longestDupSubstring(string S) {
        Init(S);
        int sz = S.length();
        int l = 2; int r = sz - 1;
        string ans = "";
        while(l <= r)
        {
            int mid = (l + r) / 2;
            bool isOK = false;
            int result = Possible(mid);
            if(result != -1)
            {
                ans = S.substr(result, mid);
                isOK = true;
            }
            if(isOK)
            {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }

    bool static cmp(const int&a, const int& b)
    {
        return Hash[a] < Hash[b] || (Hash[a] == Hash[b] && a < b);
    }
    int Possible(int len)
    {
        int c = 0;
        int pos = -1;
        for(int i = 0; i < n - len + 1; i++)
        {
            Rank[i] = i;
            Hash[i] = H[i] - H[i + len] * Xp[len]; 
        }
        sort(Rank, Rank + n - len + 1, cmp);
        for(int i = 0; i < n - len + 1; i++)
        {
            if(i == 0 || Hash[Rank[i]] != Hash[Rank[i - 1]])
            {
                c = 0;
            }
            c++;
            if(c > 1)
            {
                return Rank[i];
            }
        }
        return -1;
    }
    void Init(string s)
    {
        int x = 123;
        n = s.length();
        H = new unsigned long long[n + 1];
        Xp = new unsigned long long[n + 1];
        Hash = new unsigned long long[n + 1];
        Rank = new int[n + 1];
        H[n] = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            H[i] = H[i + 1] * x + (s[i] - 'a'); 
        }
        Xp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            Xp[i] = Xp[i - 1] * x;
        }
    }
    int n;
    
};

int main() {
    Solution s;
    cout << s.longestDupSubstring("ababc") << endl;
    return 0;
}