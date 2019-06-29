#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int sz = barcodes.size();
        map<int, int> mp;
        for(int i = 0; i < sz; i++)
        {
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            q.push(make_pair(it->second, it->first));
        }
        vector<int> ans;

        pair<int, int> last;
        if(q.size() > 0)
        {
            last = q.top();
            q.pop();
            ans.push_back(last.second);
            last.first--;
        }
        while(q.size() > 0)
        {
            pair<int, int> current = q.top();
            q.pop();
            ans.push_back(current.second);
            current.first--;
            if(last.first > 0)
            {
                q.push(last);
            }
            last = current;
        }

        return ans;
    }
};

int main() {
    
    return 0;
}