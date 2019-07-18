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

class MyCalendarThree {
public:
    map<int, int> mp;
    int mx;
    MyCalendarThree() {
        mx = 0;
    }
    
    int book(int start, int end) {
        int current = 0;
        mp[start]++;
        mp[end]--;
        

        for(auto i : mp)
        {
            current += i.second;
            if(mx < current)
            {
                mx = current;
            }
        }
        return mx;
    }
};

int main() {
    
    return 0;
}