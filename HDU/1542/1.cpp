#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

#define lson rt << 1, l, mid  
#define rson rt << 1|1, mid + 1, r  

const int MAXN = 2000 + 5;

struct SEGTREE {
	int cas;
	int Col[MAXN << 2];
	double X[MAXN << 2], Sum[MAXN << 2];
	int cnt, cntX;

	struct treeNode {
		double l, r, h;
		int s;
		treeNode() {};
		treeNode(double l, double r, double h, int s):
			l(l), r(r), h(h), s(s) {};
		bool operator < (const treeNode& tN) const {
			return h < tN.h;
		}
	} tNode[MAXN];

	bool comp (double x1, double x2) {
		
	}

	void clear() {
		memset(Sum, 0, sizeof(Sum));
		memset(Col, 0, sizeof(Col));
		cnt = 0; cntX = 0;
	}

	void init() {
		cas++;
		sort(X, X + cnt);
		cntX = unique(X, X + cnt) - X;
		sort(tNode, tNode + cnt);
	}

	void process() {
		double ans = 0;
		for(int i = 0; i < cnt - 1; i++) {
			int l = binaryFind(tNode[i].l);
			int r = binaryFind(tNode[i].r) - 1;

			update(l, r, tNode[i].s, 1, 0, cntX);
			ans += (Sum[1] * (tNode[i + 1].h - tNode[i].h));
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n", cas, ans);  
	}

	void addRectangle(double a, double b, double c, double d) {
		tNode[cnt] = treeNode(a, c, b, 1);
		X[cnt++] = a;
		tNode[cnt] = treeNode(a, c, d, -1);
		X[cnt++] = c;
	}

	void pushUp(int rt, int l, int r) {
		if (Col[rt]) Sum[rt] = X[r + 1] - X[l];
		else if(l == r) Sum[rt] = 0;
		else Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1];
	}

	void update(int L, int R, int c, int rt, int l, int r) {
		if(L <= l && r <= R) {
			Col[rt] += c;
			pushUp(rt, l, r);
			return;
		}
		int mid = (l + r) >> 1;
		if(L <= mid) update(L, R, c, lson);
		if(R > mid) update(L, R, c, rson);
		pushUp(rt, l, r);
	}

	int binaryFind(double x){  
		int lb = -1, ub = cntX - 1;  
		while(ub - lb > 1){  
			int mid = (lb + ub) >> 1;  
			if(X[mid] >= x) ub = mid;  
			else lb = mid;  
		}
		return ub;  
	}
} segTree;

int main() {
	int n;
	segTree.cas = 0;
	while(~scanf("%d", &n), n) {
		segTree.clear();
		for(int i = 0; i < n; i++) {
			double a, b, c, d;
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
			segTree.addRectangle(a, b, c, d);
		}
		segTree.init();
		segTree.process();
	}
	return 0;
}