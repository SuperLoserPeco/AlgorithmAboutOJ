#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100010;
int c[maxn], n;

int lowbit(int x) {
    return x & (-x);
}

void add(int i, int val) {
    while(i <= n) {
        c[i] += val;
        i += lowbit(i);
    }
}

int sum(int i) {
    int ret = 0;
    while(i > 0) {
        ret += c[i];
        i -= lowbit(i);
    }
    return ret;
}

int main() {
    while(scanf("%d", &n), n) {
        memset(c, 0, sizeof(c));
        int a, b;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            add(a, 1);
            add(b + 1, -1);
        }
        for(int i = 1; i <= n; i++){
            printf("%d", sum(i));
            printf(i < n ? " " : "\n");
        }
    }
}