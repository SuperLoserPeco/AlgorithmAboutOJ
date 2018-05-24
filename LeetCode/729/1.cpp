#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class MyCalendar {
public:
    set<int> numSet;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ret = true;
        for(set<int>::iterator iter = numSet.begin(); 
                                iter != numSet.end(); 
                                iter++) {
            if(*iter >= start && *iter < end){
                ret = false;
                break;
            }
        }
        if(ret){
            numSet.insert(start);
            numSet.insert(end - 1);
        }
        return ret;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */