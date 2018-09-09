#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int ans;
    int kst;
    int kthSmallest(TreeNode* root, int k) {
        kst = k;
        ans = -1;
        dfs(root, 0);
        return ans;
    }

    int dfs(TreeNode* cur, int part) {
        if(cur == NULL) return 0;
        int leftVal = dfs(cur->left, part);

        if(part + leftVal + 1 == kst) {
            ans = cur->val;
        }

        int rightVal = dfs(cur->right, part + 1 + leftVal);
        return leftVal + 1 + rightVal;
    }
};