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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* ans;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
        {
            return 0;
        }

        map<int, int> mp;
        mp[dfs(root->left, p, q)] = 1;
        mp[dfs(root->right, p, q)] = 1;
        if(root == p)
        {
            mp[1] = 1;
        }
        if(root == q)
        {
            mp[2] = 1;
        }
        if(mp[1] * 1 + mp[2] * 2 == 3 && ans == NULL)
        {
            ans = root;
        }
        return max(mp[1] * 1, mp[2] * 2);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        dfs(root, p, q);
        return ans;
    }
};

int main() {
    
    return 0;
}