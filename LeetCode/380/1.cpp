#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class RandomizedSet {
public:
    map<int, int> mp;
    int num;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
        num = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp[val] <= 0) {
            mp[val]++; num++;
            return true;
        }
        else{
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp[val] > 0) {
            mp[val]--; num--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int times = rand() % num;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if(times < it->second)
                return it->first;
            times = times - it->second;
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */