#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;

class Solution {
public:
    vector<string> vec;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        vec.push_back("abc");
        vec.push_back("def");
        vec.push_back("ghi");
        vec.push_back("jkl");
        vec.push_back("mno");
        vec.push_back("pqrs");
        vec.push_back("tuv");
        vec.push_back("wxyz");

        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int dep, string now) {
        if(dep == digits.size()) {
            if(now.size() > 0)
            ans.push_back(now);
            return;
        }

        int cur = digits[dep] - '2';
        for(int j = 0; j < vec[cur].size(); j++) {
            string next = now + vec[cur][j];
            dfs(digits, dep + 1, next);
        }
    }
};