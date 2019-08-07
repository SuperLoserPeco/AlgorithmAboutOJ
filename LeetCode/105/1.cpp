#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& pre, int preS, int preE, vector<int>& in, int inS, int inE)
    {
        if(preS > preE || inS > inE)
        {
            return NULL;
        }
        TreeNode* current = new TreeNode(pre[preS]);
        int index = inS;
        for(int i = inS; i <= inE; i++)
        {
            if(pre[preS] == in[i])
            {
                index = i;
                break;
            }
        }

        current->left = dfs(pre, preS + 1, preS + index - inS, in, inS, index - 1);
        current->right = dfs(pre, preS + index - inS + 1, preE, in, index + 1, inE);
        return current;
    }
};

int main() {
    
}