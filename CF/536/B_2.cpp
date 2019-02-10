//http://codeforces.com/contest/1106/submission/49350769
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

#define MP make_pair
#define PB emplace_back

using namespace std;

typedef long long LL;

template<typename T>
inline T read(T& x)
{
    x = 0;
    int f = 0; char ch = getchar();
    while(ch < '0' || ch > '9') {
        f |= (ch == '-');
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x == f ? -x : x;
}

int main() {
    
}