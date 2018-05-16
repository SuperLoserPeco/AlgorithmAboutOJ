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

const int maxn = 1e4 + 100;
set<int> _set[maxn];
map<string, int> mp1;
map<int, string> mp2;
int tmp[maxn];

int main(){
    mp1.clear(); mp2.clear();
    string s1, s2; int m, id = 0;
    cin >> m;
    FOR(i, m){
        cin >> s1 >> s2;
        if(!mp1[s1]) mp1[s1] = ++id, mp2[id] = s1;
        if(!mp1[s2]) mp1[s2] = ++id, mp2[id] = s2;
        int u = mp1[s1], v = mp1[s2];
        _set[u].insert(v); _set[v].insert(u);
    }
    cout << id << endl;
    REP(i, id){
        int ans = 0, maxf = 0;
        REP(j, id){
            if(i == j || _set[i].count(j)) continue;
            int num = set_intersection(_set[i].begin(), _set[i].end(),
                                       _set[j].begin(), _set[j].end(), tmp) - tmp;
            if(num > maxf){
                maxf = num; ans = 1;
            }
            else if(num == maxf) ans++;
        }
        cout << mp2[i] << " " << ans << endl;
    }
}