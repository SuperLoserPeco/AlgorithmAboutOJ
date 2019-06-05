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
    bool dfs(TreeNode* s, TreeNode* t)
    {
        bool result = find(s, t);
        if(result)
        {
            return true;
        }
        if(s->left != NULL)
        {
            result = dfs(s->left, t);
            if(result)
            {
                return true;
            }
        }
        if(s->right != NULL)
        {
            result = dfs(s->right, t);
            if(result)
            {
                return true;
            }
        }
        return false;
    }

    bool find(TreeNode* s, TreeNode* t)
    {
        if(!isSame(s, t))
        {
            return false;
        }
        if(s == NULL && t == NULL)
        {
            return true;
        }
        bool result = find(s->left, t->left);
        if(!result)
        {
            return false;
        }
        result = find(s->right, t->right);
        if(!result)
        {
            return false;
        }
        return true;
    }

    bool isSame(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == NULL && node2 == NULL)
        {
            return true;
        }
        else if(node1 == NULL || node2 == NULL)
        {
            return false;
        }
        else{
            return node1->val == node2->val;
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL)
        {
            return true;
        }
        if(s == NULL && t != NULL)
        {
            return false;
        }
        return dfs(s, t);
    }
};

int main() {
    
    return 0;
}