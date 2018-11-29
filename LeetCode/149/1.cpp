#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>

#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            map<pair<int, int>, int> count;
            int samePoints = 1;
            int maxPoints = 0;
            Point& p1 = points[i];
            for(int j = 0; j < n && j != i; j++)
            {
                Point& p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y)
                {
                    samePoints++;
                }
                else
                {
                    maxPoints = 
                    max(maxPoints, ++count[getSlops(p1, p2)]);
                }
            }
            ans = max(ans, samePoints + maxPoints);
        }
        return ans;
    }

    pair<int, int> getSlops(Point& p1, Point& p2)
    {
        const int dx = p2.x - p1.x;
        const int dy = p2.y - p1.y;
        if(dy == 0) return { p1.y, 0 };
        if(dx == 0) return { 0, p1.x };

        const int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }

    int gcd(int m, int n)
    {
        return n == 0 ? m : gcd(n, m % n);
    }
};