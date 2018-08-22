#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<int> vec_sum;
    vector<int> cur;
    void dfs(int i, int dep, int sum, int k, int n) {
        if(dep == k) {
            if(sum == n) {
                vector<int> cur_fi;
                for(int j = 0; j < k; j++) cur_fi.push_back(cur[j]);
                ans.push_back(cur_fi);
            }
            return;
        }
        if((vec_sum[8] - vec_sum[(8 - (k - dep))]) < (n - sum)) return;
        for(int j = i + 1; j <= 9; j++) {
            cur[dep] = j;
            dfs(j, dep + 1, sum + j, k, n);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        cur.clear();
        if(k == 0 || k > 9) return ans;
        for(int i = 1; i <= 9; i++) {
            int curv = i;
            int sz = vec_sum.size();
            if(sz > 0) {
                curv += vec_sum[sz - 1];
            }
            vec_sum.push_back(curv);
        }
        for(int i = 0; i < 9; i++) cur.push_back(0);

        for(int i = 1; i <= 9; i++) {
            cur[0] = i;
            dfs(i, 1, i, k, n);
        }
        return ans;
    }
};