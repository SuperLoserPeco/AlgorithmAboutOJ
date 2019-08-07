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
    unsigned long long h, w;
    cin >> h >> w;
    unsigned long long divided = 998244353;
    unsigned long long sum = h + w;
    unsigned long long ans = 1;
    unsigned long long pwd = 2;
    if(h == 1 && w == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if(h == 1 || w == 1)
    {
        sum--;
    }
    while(sum)
    {
        if(sum & 1)
        {
            ans *= pwd;
            ans %= divided;
        }
        pwd *= pwd;
        pwd %= divided;
        sum >>= 1;
    }
    cout << ans;
    return 0;
}