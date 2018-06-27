#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> ret;

    void dfs(int cur, int n) {
        for(int i = 0; i < 10; i++) {
            int next = cur * 10 + i;
            if(next != 0 && next <= n) {
                ret.push_back(next);
                dfs(next, n);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        dfs(0, n);
        return ret;
    }
};