#include <vector>
#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>
#include <queue>

#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {
public:
    vector<TreeNode*> vec;
    
    CBTInserter(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            TreeNode* cur = Q.front();
            Q.pop();
            if(cur == NULL)
            {
                continue;
            }
            vec.push_back(cur);


            if(cur->left != NULL)
            {
                Q.push(cur->left);
            }
            if(cur->right != NULL);
            {
                Q.push(cur->right);
            }
        }
    }
    
    int insert(int v) {
        int count = vec.size();
        TreeNode* node = new TreeNode(v);
        int ret = -1;
        if(count > 0) {
            ret = vec[(count - 1) / 2]->val;
            if((count - 1) % 2 == 0)
            {
                vec[(count - 1) / 2]->left = node;
            }
            else {
                vec[(count - 1) / 2]->right = node;
            }
        }
        vec.push_back(node);
        return ret;
    }
    
    TreeNode* get_root() {
        return vec.size() == 0 ? NULL : vec[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */