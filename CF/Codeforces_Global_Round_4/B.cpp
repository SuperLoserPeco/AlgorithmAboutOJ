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


int main() {
    string s;
    cin >> s;
    int sz = s.length();
    vector<int> wNumLeft(sz + 3, 0);
    vector<int> wNumRight(sz + 3, 0);
    int currentV = 0;
    for(int i = 0; i < sz; i++)
    {
        if(s[i] == 'v')
        {
            currentV++;
            if(i + 1 >= sz || s[i + 1] != 'v')
            {
                wNumLeft[i] = currentV - 1;
                wNumRight[i] = currentV - 1; 
            }
        }
        else{
            currentV = 0;
        }
    }
    for(int i = 1; i < sz; i++)
    {
        wNumLeft[i] += wNumLeft[i - 1];
    }
    for(int i = sz - 2; i >= 0; i--)
    {
        wNumRight[i] += wNumRight[i + 1];
    }
    long long ans = 0;
    for(int i = 1; i < sz - 1; i++)
    {
        if(s[i] == 'o')
        {
            long long l = wNumLeft[i - 1];
            long long r = wNumRight[i + 1];
            ans += (l * r);
        }
    }
    cout << ans ;
    return 0;
}