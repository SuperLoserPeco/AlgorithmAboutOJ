#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class MyCalendar {
public:
    vector<pair<int, int> > vecPair;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ret = true;
        int sz = vecPair.size();
        for(int i = 0; i < sz; i++) {
            int l = vecPair[i].first;
            int r = vecPair[i].second;
            if((start <= l && l < end) ||
                (start <= r && r < end) ||
                (l <= start && end - 1 <= r)){
                ret = false;
            }
        }
        if(ret){
            vecPair.push_back(make_pair(start, end - 1));
        }
        return ret;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */