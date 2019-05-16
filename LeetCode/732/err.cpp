#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

class MyCalendarThree {
public:
    vector<pair<int, int>> one;
    MyCalendarThree() {
        currentMax = 1;
    }
    int currentMax;
    int book(int start, int end) {
        end = end - 1;
        int cnt = 1;
        int sz = one.size();
        int saveStart = start;
        int saveEnd = end;
        for(int i = 0; i < sz; i++)
        {
            if(!(end < one[i].first || start > one[i].second))
            {
                cnt++;
                start = max(one[i].first, start);
                end = min(one[i].second, end);
            }
        }
        currentMax = max(currentMax, cnt);
        one.push_back(make_pair<int, int>((int)saveStart, (int)saveEnd));
        return currentMax;
    }
};

int main() {
    
    return 0;
}