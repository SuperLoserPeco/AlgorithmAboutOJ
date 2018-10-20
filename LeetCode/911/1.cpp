#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <map>
#include <set>

#include <algorithm>
using namespace std;

class TopVotedCandidate {
public:
    int sz;
    int* result;
    map<int, int> mp;
    set<pair<int, int>> st;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        sz = persons.size();
        result = new int[sz];
        for(int i = 0; i < sz; i++)
        {
            set<pair<int, int>>::iterator iter = 
            find(st.begin(), st.end(), make_pair(mp[persons[i]], persons[i]));
            if(iter == st.end())
            {
                
            }
        }
    }
    
    int q(int t) {
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */