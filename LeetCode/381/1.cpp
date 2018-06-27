#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class RandomizedCollection {
public:
    map<int, int> mp;
    int num;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        num = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(mp[val] <= 0) {
            mp[val]++; num++;
            return true;
        }
        else{
            mp[val]++; num++;
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp[val] > 0) {
            mp[val]--; num--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int times = rand() % num;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if(times < it->second)
                return it->first;
            times = times - it->second;
        }
    }
};