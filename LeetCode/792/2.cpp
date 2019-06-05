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
    unordered_map<char,set<int>> record;
    set<int>::iterator it;
    int total,rec,flag;
    int numMatchingSubseq(string S, vector<string>& words) {
        for(int i=0;i<S.size();i++) record[S[i]].insert(i);
        for(auto s: words) {
            rec = -1;flag = 1;
            for(int i=0;i<s.length();i++) {
                it = record[s[i]].upper_bound(rec);
                if(it==record[s[i]].end()) {
                    flag = 0;break;
                }
                rec = *it;
            }
            if(flag) total++;
        }
        return total;
    }
};

int main() {
    
    return 0;
}