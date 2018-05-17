#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
using namespace std;

#define wh while
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i <= n; i++)
#define sf scanf
#define pf printf
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define clr(abc,z) memset(abc,z,sizeof(abc))


typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const int maxn = 1e6 + 100;
bool vis[maxn] = {0};

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    if(n < m) swap(n, m);
    REP(i, n){
        if(vis[i]) continue;
        ans++;
        int dir = 1, cur = i;
        wh(true){
            if(vis[cur]) break;
            vis[cur] = true;
            if(dir == 1){
                if(cur + m - 1 == n ||
                   cur + 2 * (m - 1) == n){
                    if(cur + 2 * (m - 1) == n) vis[n] = true;
                    break;
                }
                else if(cur + 2 * (m - 1) > n){
                    cur = 2 * n - (cur + 2 * (m - 1));
                    dir = 0;
                    if(cur < 1){
                        cur = 2 - cur; dir = 1;
                    }
                }
                else{
                    cur = cur + 2 * (m - 1);
                }
            }
            else{
                if(cur - (m - 1) == 1 ||
                   cur - 2 * (m - 1) == 1){
                    if(cur - 2 * (m - 1) == 1) vis[1] = true;
                    break;
                }
                else if(cur - 2 * (m - 1) < 1){
                    cur = 2 * (m - 1) - cur + 2;
                    dir = 1;
                    if(cur > n){
                        cur = 2 * n - cur; dir = 0;
                    }
                }
                else{
                    cur = cur - 2 * (m - 1);
                }
            }
        }
        dir = 0; cur = i; vis[cur] = false;
        wh(true){
            if(vis[cur]) break;
            vis[cur] = true;
            if(dir == 1){
                if(cur + m - 1 == n ||
                   cur + 2 * (m - 1) == n){
                    if(cur + 2 * (m - 1) == n) vis[n] = true;
                    break;
                }
                else if(cur + 2 * (m - 1) > n){
                    cur = 2 * n - (cur + 2 * (m - 1));
                    dir = 0;
                    if(cur < 1){
                        cur = 2 - cur; dir = 1;
                    }
                }
                else{
                    cur = cur + 2 * (m - 1);
                }
            }
            else{
                if(cur - (m - 1) == 1 ||
                   cur - 2 * (m - 1) == 1){
                    if(cur - 2 * (m - 1) == 1) vis[1] = true;
                    break;
                }
                else if(cur - 2 * (m - 1) < 1){
                    cur = 2 * (m - 1) - cur + 2;
                    dir = 1;
                    if(cur > n){
                        cur = 2 * n - cur; dir = 0;
                    }
                }
                else{
                    cur = cur - 2 * (m - 1);
                }
            }
        }
    }
    pf("%d\n", ans);
}