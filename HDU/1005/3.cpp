#include <cstdio>

//temp code
//手写 矩阵幂

int cur[2][2];
int pow[2][2];
int ans[2][2];

int main() {
    int A, B, n;
    int last1 = 1, last2 = 1;
    while(scanf("%d%d%d", &A, &B, &n) != -1) {
        ans[0][0] = ans[1][1] = 1;
        ans[0][1] = ans[1][0] = 0;
        if(!A && !B && !n) break;
        int cur = 1;
        int powNum = n - 2;
        pow[0][0] = A; pow[0][1] = B;
        pow[1][0] = 1; pow[1][1] = 0;
        while(powNum > 0){
            if(powNum & 1) {
                int r00 = (pow[0][0] * ans[0][0] + pow[0][1] * ans[1][0]) % 7;
                int r01 = (pow[0][0] * ans[0][1] + pow[0][1] * ans[1][1]) % 7;
                int r10 = (pow[1][0] * ans[0][0] + pow[1][1] * ans[1][0]) % 7;
                int r11 = (pow[1][0] * ans[0][1] + pow[1][1] * ans[1][1]) % 7;
                ans[0][0] = r00;
                ans[0][1] = r01;
                ans[1][0] = r10;
                ans[1][1] = r11;
            }
            int r00 = (pow[0][0] * pow[0][0] + pow[0][1] * pow[1][0]) % 7;
            int r01 = (pow[0][0] * pow[0][1] + pow[0][1] * pow[1][1]) % 7;
            int r10 = (pow[1][0] * pow[0][0] + pow[1][1] * pow[1][0]) % 7;
            int r11 = (pow[1][0] * pow[0][1] + pow[1][1] * pow[1][1]) % 7;
            pow[0][0] = r00;
            pow[0][1] = r01;
            pow[1][0] = r10;
            pow[1][1] = r11;
            powNum >>= 1;
        }
        cur = (ans[0][0] + ans[0][1]) % 7;
        printf("%d\n", cur);
    }
}