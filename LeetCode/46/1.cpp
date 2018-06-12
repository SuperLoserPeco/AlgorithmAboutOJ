#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int sz;
    bool vis[100000];
    int num[100000];
    void dfs(int dep, vector<int>& nums) {
        if(dep == nums.size()) {
            vector<int> result;
            for(int i = 0; i < dep; i++){
                result.push_back(nums[num[i]]);
            }
            ans.push_back(result);
            return;
        }

        for(int i = 1; i <= sz; i++) {
            if(!vis[i]) {
                vis[i] = true;
                num[dep] = i - 1;
                dfs(dep + 1, nums);
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        for(int i = 0; i <= sz; i++) vis[sz] = false;
        dfs(0, nums);
        return ans;
    }
};