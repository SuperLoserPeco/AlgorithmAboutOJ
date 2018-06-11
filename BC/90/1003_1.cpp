#include <cstdio>
#include <list>

inline int read() {
    int data = 0; char ch;
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') {
        data = data * 10 + ch - '0';
        ch = getchar();
    }
    return data;
}

struct list {
    struct node {
        int v;
        node* next;
    };

    node* f;
    unsigned int sz;

    list(): f(0), sz(0u) {};
    unsigned int size() {
        return sz;
    }
    int front() {
        return f->v;
    }
    void pop_front() {
        node* s = f;
        f = f->next;
        delete s;
        sz--;
    }
    void push_front(const int& v) {
        node* nd = new node;
        nd->v = v;
        nd->next = f;
        f = nd;
        sz++;
    }
    void clear() {
        f = (node*) 0;
        sz = 0u;
    }
};

//suffixtree
////////////////////////////////////////////////////////////////////////////////////////////////////
const int SFT_NUM = 1e5 + 1000;
int sftSum[SFT_NUM];
int lowbit(const int &a) {
    return a & (-a);
}
void add(int o, const int& v) {
    while(o < SFT_NUM) {
        sftSum[o] += v;
        o += lowbit(o);
    }
}
int sftsum(int o) {
    int ans = 0;
    while(o > 0) {
        ans += sftSum[o];
        o -= lowbit(o);
    }
    return ans;
}
int sftinit(int N) {
    for(int i = 1; i <= N; i++)
        sftSum[i] = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

const int maxN = 1e5 + 1000;
const int maxQ = 1e5 + 1000;
const int maxC = 1e6 + 1000;

int C[maxC], A[maxN];
bool isdifferent[maxN];
list F[maxC];
int N, Q;

void mainFunc() {
    N = read();
    Q = read();
    for(int i = 1; i < maxC; i++) {
        F[i].clear();
        C[i] = i;
    }
    sftinit(N);
    for(int i = 1; i <= N; i++) {
        A[i] = read();
        F[C[A[i]]].push_front(i);
        if(isdifferent[i] = (A[i] != A[i - 1])) {
            add(i, 1);
        }
    }

    for(int t = 1; t <= Q; t++) {
        int op, x, y;
        op = read();
        x = read();
        y = read();

        if(op == 1) {
            if(x == y) continue;
        }
        else {
            // printf("%d\n", sftsum(y) - )
        }
    }
        
}

int main() {
    int T;
    T = read();
    while(T--) {
        mainFunc();
    }
}