#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

class LRUCache {
public:
    deque<int> Q;
    int sz;
    map<int, int> mp;
    LRUCache(int capacity) {
        cout << "capacity" << capacity << endl;
        sz = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i < Q.size(); i++) {
            if(Q[i] == key) {
                cout << *(Q.begin() + i) << endl;
                Q.erase(Q.begin() + i);
                Q.push_back(key);
                break;
            }
        }
        return mp[key];
    }
    
    void put(int key, int value) {
        if(Q.size() > sz) {
            int lruKey = Q.front();
            Q.pop_front();
            mp[lruKey] = -1;
        }
        Q.push_back(key);
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */