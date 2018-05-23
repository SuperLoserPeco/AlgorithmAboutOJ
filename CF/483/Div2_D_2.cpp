#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 5e3 + 5;
const int maxnbit = 30;
int a[maxn];
int b[maxn][maxnbit];


int main() {
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= maxnbit; i++)
        b[0][i] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        for(int j = 1; j <= maxnbit; j++){
            b[i][j] = ((a[i] >> (j - 1)) & 1) ? 1 : 0;
            b[i][j] = b[i][j] + b[i - 1][j];
        }
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        long long ans = 0;
        for(int j = 1; j <= maxnbit; j++) {
            ans = ans + (long long)((b[r][j] - b[l - 1][j]) % 2 == 1 ? (1 << (j - 1)) : 0);
        }
        printf("%I64d\n", ans);
    }
}