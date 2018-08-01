#include <bits/stdc++.h>
using namespace std;

//答案是对的 但是为什么是这样啊
//二分图

const int maxn = 4e5 + 100;
int fa[maxn];
int weight[maxn];

int find(int x) {
    if(fa[fa[x]] != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

void unit(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return ;
    if(weight[a] > weight[b]) {
        weight[a] += weight[b];
        fa[b] = a;
    }
    else {
        weight[b] += weight[a];
        fa[a] = b;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n + m; i++) {
        fa[i] = i; weight[i] = i;
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        unit(a, b + n);
    }

    int ans = -1;
    for(int i = 1; i <= n + m; i++) {
        if(fa[i] == i) ans++;
    }

    cout << ans << endl;
    return 0;
}
