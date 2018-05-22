#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 5e3 + 5;
int a[maxn];

int main() {
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        long long ans = 0;
        for(int j = l; j <= r; j++) ans = ans | (long long)a[j];
        printf("%lld\n", ans);
    }
}