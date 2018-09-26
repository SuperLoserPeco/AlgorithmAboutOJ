#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

struct Edge{
    int u, v, dist;
    Edge() {}
    Edge(int u, int v, int d) : u(u), v(v), dist(d) {};

    bool operator < (const Edge& rhs) const {
        return dist < rhs.dist;
    }
};


const int maxn = 1e3 + 10;
const int maxm = 15000 + 10;
class Kruskal{
private:
    int n, m;
    Edge edges[maxm];
    int fa[maxn];
    int findSet(int x) {
        return fa[x] == -1 ? x : fa[x] = findSet(fa[x]);
    }
public:
    vector<int> eIds;

    void Init(int n) {
        memset(fa, -1, sizeof(fa));
        this->n = n; m = 0;
        eIds.clear();
    }

    void AddEdge(int u, int v, int dist) {
        edges[m++] = Edge(u, v, dist);
    }

    int Main() {
        sort(edges, edges + m);
        for(int i = 0; i < m; i++) {
            int u = edges[i].u, v = edges[i].v;
            if(findSet(u) != findSet(v)) {
                eIds.push_back(i);
                fa[findSet(u)] = findSet(v);
                if(eIds.size() >= n - 1) return i;
            }
        }
        return -1;
    }   

    Edge GetEdgeById(int id) {
        return edges[id];
    } 
} kruskal;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    kruskal.Init(n);
    for(int i = 0; i < m; i++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        kruskal.AddEdge(u, v, d);
    }
    int id = kruskal.Main();
    printf("%d\n", kruskal.GetEdgeById(id).dist);
    printf("%d\n", n - 1);
    for(int i = 0; i < n - 1; i++) {
        printf("%d %d\n"
            , kruskal.GetEdgeById(kruskal.eIds[i]).u
            , kruskal.GetEdgeById(kruskal.eIds[i]).v);
    }
    return 0;
}