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
    struct Node{
        TreeNode* parent;
        int dir;
        int preS;
        int preE;
        int inS;
        int inE;
    };

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {


        queue<Node> Q;
        TreeNode* ret = NULL;
        Q.push({NULL, 0, 0, preorder.size() - 1, 0, inorder.size() - 1});
        while(!Q.empty())
        {
            Node current = Q.front();
            Q.pop();
            if(current.inS > current.inE || current.preS > current.preE)
            {
                continue;
            }
            TreeNode* now = NULL;
            if(current.parent == NULL)
            {
                ret = new TreeNode(preorder[current.preS]);
                now = ret;
            }
            else{
                if(current.dir == 0)
                {
                    current.parent->left = new TreeNode(preorder[current.preS]);
                    now = current.parent->left;
                }
                else{
                    current.parent->right = new TreeNode(preorder[current.preS]);
                    now = current.parent->right;
                }
            }
            int index = current.inS;
            for(int i = current.inS; i <= current.inE; i++)
            {
                if(preorder[current.preS] == inorder[i])
                {
                    index = i;
                    break;
                }
            }
            Node l = {now, 0,
                current.preS + 1, current.preS + index - current.inS, 
                current.inS, index - 1};
            Node r = {now, 1,
                current.preS + index - current.inS + 1, current.preE,
                index + 1, current.inE};
            Q.push(l);
            Q.push(r);
        }
        return ret;
    }
};

int main() {
    
}