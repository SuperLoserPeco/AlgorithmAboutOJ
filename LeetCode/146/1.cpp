#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
using namespace std;

class LRUCache {
public:
    deque<int> Q;
    int sz;
    map<int, int> mp;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        if(Q.size() > sz) {

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