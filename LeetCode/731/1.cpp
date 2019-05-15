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

class MyCalendarTwo {
public:
    vector<pair<int, int>> one;
    vector<pair<int, int>> two;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        end = end - 1;
        int cnt = two.size();
        for(int i = 0; i < cnt; i++)
        {
            if(!(start > two[i].second|| end < two[i].first))
            {
                return false;
            }
        }
        cnt = one.size();
        for(int i = 0; i < cnt; i++)
        {
            if(!(start > one[i].second || end < one[i].first))
            {
                two.push_back(make_pair<int, int>((int)max(one[i].first, start), (int)min(one[i].second, end)));
            }
        }
        one.push_back(make_pair<int, int>((int)start, (int)end) );
        return true;
    }
};

int main() {
    
    return 0;
}