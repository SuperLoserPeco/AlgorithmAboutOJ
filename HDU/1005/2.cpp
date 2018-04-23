#include <cstdio>
//TLE

int main() {
    int A, B, n;
    int last1 = 1, last2 = 1;
    while(scanf("%d%d%d", &A, &B, &n) != -1) {
        if(!A && !B && !n) break;
        int cur = 1;
        for(int i = 3; i <= n; i++){
            cur = (last1 * A + last2 * B) % 7;
            last2 = last1;
            last1 = cur;
        }
        printf("%d\n", cur);
    }
}