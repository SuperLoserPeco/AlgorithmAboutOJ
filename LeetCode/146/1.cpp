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
        sz = capacity;
    }
    
    int get(int key) {
        visit(key);
        map<int, int>::iterator iter = mp.find(key);
        if(iter == mp.end()) return -1;

        return mp[key];
    }
    
    void put(int key, int value) {
        map<int, int>::iterator iter = mp.find(key);
        if(iter != mp.end()) {
            visit(key);
            mp[key] = value;
            return;
        }
        if(Q.size() >= sz) {
            int lruKey = Q.front();
            Q.pop_front();
            deleteKey(lruKey);
        }
        Q.push_back(key);
        mp[key] = value;
    }

    void visit(int key) {
        for(int i = 0; i < Q.size(); i++) {
            if(Q[i] == key) {
                Q.erase(Q.begin() + i);
                Q.push_back(key);
                break;
            }
        }
    }

    void deleteKey(int key) {
        map<int, int>::iterator iter = mp.find(key);
        if(iter != mp.end()) {
            mp.erase(iter);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
/**
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

我的标准输出

capacity2
1
2
3
4

我的答案

[null,null,null,1,null,2,null,-1,3,4]
预期答案

[null,null,null,1,null,-1,null,-1,3,4]
**/

/**
输入：["LRUCache","get","put","get","put","put","get","get"]
                    [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
输出：[null,-1,null,-1,null,null,2,-1]
预期：[null,-1,null,-1,null,null,2,6]

capacity2
key before = 2

key after = 2

key before = 1
2 
key after = 1
2 
key before = 1
1 1 
key after = 1
1 1 
key before = 2
1 1 
key after = 2
1 1
**/