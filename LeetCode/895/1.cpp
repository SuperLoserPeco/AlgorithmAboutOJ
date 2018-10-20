#include <set>
#include <map>

using namespace std;

class FreqStack {
public:
    map<int, int> mp;
    map<int, int> idx;
    int cnt;
    set<pair<int, pair<int, int>>> st;
    FreqStack() {
        mp.clear();
        st.clear();
        cnt = 0;
    }
    
    void push(int x) {
        if(idx[x] > 0)
        {
            int num = mp[x];
            set<pair<int, pair<int, int>>>::iterator iter = 
                find(st.begin(), st.end(), make_pair(num, make_pair(idx[x], num)));
            if(iter != st.end())
            {
                st.erase(iter);
            }
        }
        mp[x]++;
        idx[x] = cnt++;
        st.insert(make_pair(mp[x], make_pair(idx[x], x)));
        // st.insert(make_pair(mp[x], x));
    }
    
    int pop() {
        
        set<pair<int, pair<int, int>>>::iterator now = st.end();
        now--;
        int ret = (*now).second.second;
        // mp[]
    }
};
