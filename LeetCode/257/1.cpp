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
    vector<string> dfs(TreeNode* current)
    {
        vector<string> ret;
        if(current == NULL)
        {
            return ret;
        }
        if(current->left == NULL && current->right == NULL)
        {
            ret.push_back(to_string(current->val));
            return ret;
        }
        if(current->left != NULL)
        {
            vector<string> tail = dfs(current->left);
            int sz = tail.size();
            for(int i = 0; i < sz; i++)
            {
                string s = to_string(current->val) + "->" + tail[i];
                ret.push_back(s);
            }
        }
        if(current->right != NULL)
        {
            vector<string> tail = dfs(current->right);
            int sz = tail.size();
            for(int i = 0; i < sz; i++)
            {
                string s = to_string(current->val) + "->" + tail[i];
                ret.push_back(s);
            }
        }
        return ret;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        return dfs(root);
    }
};

int main() {
    
    return 0;
}