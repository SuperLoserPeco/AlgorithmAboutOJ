//MLE
#include <cstdio>

const int maxn = 1e8 + 100;
int dp[maxn];

int main() {
    int A, B, n;
    dp[1] = dp[2] = 1;
    while(scanf("%d%d%d", &A, &B, &n) != -1) {
        if(!A && !B && !n) break;
        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i - 1] * A + dp[i - 2] * B) % 7;
        }
        printf("%d\n", dp[n]);
    }
}