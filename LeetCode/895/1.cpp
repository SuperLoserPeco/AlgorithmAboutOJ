#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <algorithm>
using namespace std;

class FreqStack {
public:
    map<int, int> mp;
    map<int, int> idx;
    map<int, int> lastIdx;
    int cnt;
    set<pair<int, pair<int, int>>> st;
    FreqStack() {
        mp.clear();
        st.clear();
        lastIdx.clear();
        cnt = 1;
    }
    
    void push(int x) {
        if(idx[x] > 0)
        {
            int num = mp[x];
            set<pair<int, pair<int, int>>>::iterator iter = 
                find(st.begin(), st.end(), make_pair(num, make_pair(idx[x], x)));
            if(iter != st.end())
            {
                st.erase(iter);
            }
        }
        mp[x]++;
        int last = idx[x];
        idx[x] = cnt++;
        lastIdx[idx[x]] = last;
        st.insert(make_pair(mp[x], make_pair(idx[x], x)));
    }
    
    int pop() {
        set<pair<int, pair<int, int>>>::iterator now = st.end();
        now--;
        int ret = (*now).second.second;
        mp[ret]--;
        idx[ret] = lastIdx[idx[ret]];
        st.erase(now);
        st.insert(make_pair(mp[ret], make_pair(idx[ret], ret)));
        return ret;
    }
};
