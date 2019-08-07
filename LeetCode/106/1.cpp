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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, 
                        postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTree
        (vector<int>& in, int inS, int inE, 
            vector<int>& post, int postS, int postE)
    {
        if(inS > inE || postS > postE)
        {
            return NULL;
        }
        TreeNode* current = new TreeNode(post[postE]);
        int index = inS;
        for(int i = inS; i <= inE; i++)
        {
            if(in[i] == post[postE])
            {
                index = i;
                break;
            }
        }
        current->left = buildTree(in, inS, index - 1, post, postS,  postS + (index - 1 - inS));
        current->right = buildTree(in, index + 1, inE, post, postE - 1 - (inE - index - 1), postE - 1);
        return current;
    }
};

int main() {
    
}