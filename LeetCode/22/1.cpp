#include <vector>
#include <iostream>
#include <queue>
using namespace std;

//not finished

class Solution {
public:
    vector<string> ans;

    struct State {
        string stat;
        int dep;
    };
    vector<string> generateParenthesis(int n) {
        queue<State> Q;
        State init;
        init.stat = "";
        init.dep = 0;
        Q.push(init);
        while(!Q.empty()) {
            State cur = Q.front();
            Q.pop();
            
            if(cur.stat.length() == n * 2) {
                if(cur.dep == 0)
                ans.push_back(cur.stat);
                continue;
            }

            for(int i = 0; i < 2; i++) {
                State nst;
                if(cur.dep < n) {
                    nst.dep = cur.dep + 1;
                    nst.stat = cur.stat + "(";
                    Q.push(nst);
                }
                if(cur.dep > 0) {
                    nst.dep = cur.dep - 1;
                    nst.stat = cur.stat + ")";
                    Q.push(nst);
                }
            }
        }
        return ans;
    }
};