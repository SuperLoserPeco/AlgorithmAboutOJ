#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>

#include <algorithm>
using namespace std;

class AllOne {
public:
    set<pair<int, string>> st;
    map<string, int> mp;
    /** Initialize your data structure here. */
    AllOne() {
        st.clear();
        mp.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(mp[key] > 0) {
            set<pair<int, string>>::iterator iter
            = find(st.begin(), st.end(), make_pair(mp[key], key));
            if(iter != st.end()) st.erase(iter);
        }
        mp[key]++;
        st.insert(make_pair(mp[key], key));
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mp[key] > 0) {
            set<pair<int, string>>::iterator iter
            = find(st.begin(), st.end(), make_pair(mp[key], key));
            if(iter != st.end()) st.erase(iter);
        }
        mp[key]--;
        if(mp[key] > 0) {
            st.insert(make_pair(mp[key], key));
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(st.size() == 0) {
            return "";
        }
        set<pair<int, string>>::iterator iter = st.end();
        return (*(--iter)).second;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(st.size() == 0) {
            return "";
        }
        cout << "获得最小key " << (*(st.begin())).second << endl;
        return (*(st.begin())).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */