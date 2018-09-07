#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>

#include <sstream>
using namespace std;

class Solution {
public:
    struct Line {
        int y1, y2, x;
        int z;
        int type;
        Line(int y1, int y2, int x, int z, int type) : y1(y1), y2(y2), x(x), z(z), type(type){}
        Line() {}
        bool operator<(Line& rhs) {
            if(x != rhs.x) return x < rhs.x;
            else return z < rhs.z;
        }
    };

    vector<Line> cur;
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<Line> vec;
        
        vec.push_back(Line(D, B, A, 1, 1));
        vec.push_back(Line(D, B, C, -1, 1));
        vec.push_back(Line(H, F, E, 1, 2));
        vec.push_back(Line(H, F, G, -1, 2));
        sort(vec.begin(), vec.end());
        int ret = 0;
        cur.push_back(vec[0]);
        for(int i = 1; i < vec.size(); i++) {
            int y = calcY();
            ret += (y * (vec[i].x - vec[i - 1].x));

            addLine(vec[i]);
        }

        return ret;
    }

    void addLine(Line x) {
        if(x.z == -1) {
            for(int i = 0; i < cur.size(); i++)
                if(cur[i].type == x.type && cur[i].z == 1) {
                    cur.erase(cur.begin() + i);
                    break;
                }
        }
        else{
            cur.push_back(x);
        }
    }

    int calcY() {
        sort(cur.begin(), cur.end(), cmp);
        if(cur.size() == 1) return cur[0].y1 - cur[0].y2;
        else if(cur.size() == 0) {
            return 0;
        }
        else{
            if(cur[1].y2 > cur[0].y1) {
                return (cur[0].y1 - cur[0].y2) + (cur[1].y1 - cur[1].y2);
            }
            else if(cur[1].y1 > cur[0].y1) {
                return cur[1].y1 - cur[0].y2;
            }
            else {
                return cur[0].y1 - cur[0].y2;
            }
        }
    }

    static bool cmp(Line&a, Line& b) {
        return a.y2 < b.y2;
    }
};