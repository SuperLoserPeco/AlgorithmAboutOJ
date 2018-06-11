#include <vector>
using namespace std;

struct Line {
    int x;
    int y1, y2;

};

const int maxn = 1e5 + 100;

class Solution {
public:
    
    struct SegTree {
        struct Node{
            int flag;
        } node[maxn];
        void init(int l, int r, int rt) {
            node[rt].flag = 0;

            if(l == r) return;
            int md = (l + r) / 2;
            init(l, md, rt * 2);
            init(md + 1, r, rt * 2 + 1);
        }

        void update(int l, int r, int L, int R, int rt, bool flag) {

        }

        long long query(int l, int r, int rt) {

        }
    };

    vector<int> xNum;
    vector<int> yNum;
    int rectangleArea(vector<vector<int>>& rectangles) {
        int sz = rectangles.size();

        for(int i = 0; i < sz; i++) {
            xNum.push_back(rectangles[i][0]);
            xNum.push_back(rectangles[i][2]);

            yNum.push_back(rectangles[i][1]);
            yNum.push_back(rectangles[i][3]);
        }
        sort(xNum.begin(), xNum.end());
        sort(yNum.begin(), yNum.end());
        xNum.erase(unique(xNum.begin(), xNum.end()), xNum.end());
        yNum.erase(unique(yNum.begin(), yNum.end()), yNum.end());

        for(int i = 0; i < sz; i++) {

        }
    }
};