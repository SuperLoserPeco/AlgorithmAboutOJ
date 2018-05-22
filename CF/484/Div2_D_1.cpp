#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
map<int, int> mp;
int a[maxn], l[maxn], r[maxn];
bool vis[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i;
    }
    sort(a + 1, a + n + 1);
    memset(vis, 0, sizeof(vis));

    int len = 0, k = 0, cnt = 0, curCnt = 0;
    for(int i = 1; i <= n; i++) {
        int pos = mp[a[i]];
        vis[pos] = 1;
        if(vis[pos - 1] == 1 && vis[pos + 1] == 1) {
            --cnt;
            r[l[pos - 1]] = r[pos] = r[pos + 1];
            l[r[pos + 1]] = l[pos] = l[pos - 1];
        }
        else if(vis[pos - 1] == 1) {
            l[pos] = l[pos - 1];
            r[pos] = r[l[pos - 1]] = pos;
        }
        else if(vis[pos + 1] == 1) {
            r[pos] = r[pos + 1];
            l[pos] = l[r[pos + 1]] = pos;
        }
        else {
            ++cnt;
            l[pos] = pos; r[pos] = pos;
        }
        len = max(len, (r[pos] - l[pos] + 1));
        if(len * cnt == i && cnt > curCnt) {
            curCnt = cnt;
            k = a[i] + 1;
        }
    }
    printf("%d\n", k);
}