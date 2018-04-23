//https://blog.csdn.net/qq_18661257/article/details/47622677 看看
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

const int MAXN = 2000 + 5;

struct SEGTREE {
	int Col[MAXN << 2], X[MAXN << 2], Sum[MAXN << 2];
	int cnt, res;

	struct treeNode {
		double tL, tR, tH;
		int tS;
		treeNode() {}
		treeNode(double l, double r, double h, int s):
			tL(l), tR(r), tH(h), tS(s) {}
	} tNode[MAXN];

	void clear() {
		memset(Sum, 0, sizeof(Sum));
		memset(Col, 0, sizeof(Col));
		cnt = 0; res = 0;
	}

	void init() {
		sort(X, X + cnt);
		sort(tNode, tNode + cnt);
	}

	void addRectangle(double a, double b, double c, double d) {
		tNode[cnt] = treeNode(a, c, b, 1);
		X[cnt++] = a;
		tNode[cnt] = treeNode(a, c, d, -1);
		X[cnt++] = c;
	}

	void pushUp(int rt, int l, int r) {

	}
} segTree;

int main() {
	int cas = 1, n;
	while(~scanf("%d", &n), n) {
		segTree.clear();
		for(int i = 0; i < n; i++) {
			double a, b, c, d;
			scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		}
	}
	return 0;
}