#include <vector>
#include <queue>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 //前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        deque<TreeNode*> Q;
        if(root != NULL)
        Q.push_front(root);
        vector<int> ret;
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            cout << cur->val << endl;
            Q.pop_front();
            ret.push_back(cur->val);
            if(cur->right != NULL) Q.push_front(cur->right);
            if(cur->left != NULL) Q.push_front(cur->left);

        }
        return ret;
    }
};