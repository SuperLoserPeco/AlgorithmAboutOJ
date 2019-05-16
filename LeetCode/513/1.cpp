#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int currentDep;
    int ans;
    void dfs(TreeNode* root, int dep)
    {
        if(dep > currentDep)
        {
            currentDep = dep;
            ans = root->val;
        }
        if(root->left != NULL)
        {
            dfs(root->left, dep + 1);
        }
        if(root->right != NULL)
        {
            dfs(root->right, dep + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        currentDep = -1;
        dfs(root, 0);
        return ans;
    }
};

int main() {
    
    return 0;
}