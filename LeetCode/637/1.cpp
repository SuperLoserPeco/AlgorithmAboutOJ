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
    struct Node{
        TreeNode* cur;
        int ceng;
    };
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> vec;
        vector<double> ret;
        map<int, int> mpNum;
        map<int, double> mpSum;

        Node node;
        node.cur = root;
        node.ceng = 0;
        queue<Node> Q;
        int mxSize = 0;
        if(root != NULL)
        {
            Q.push(node);
        }
        while(!Q.empty())
        {
            Node cur = Q.front();
            cout << cur.cur->val << endl;
            Q.pop();
            mpSum[cur.ceng] += cur.cur->val;
            mpNum[cur.ceng] += 1;
            mxSize = max(mxSize, cur.ceng);
            if(cur.cur->left != NULL)
            {
                Node nextL;
                nextL.ceng = cur.ceng + 1;
                nextL.cur = cur.cur->left;
                Q.push(nextL);
            }
            if(cur.cur->right != NULL)
            {
                Node nextR;
                nextR.ceng = cur.ceng + 1;
                nextR.cur = cur.cur->right;
                Q.push(nextR);
            }
        }
        for(int i = 0; i <= mxSize; i++)
        {
            if(mpNum[i] == 0)
            {
                ret.push_back(0);
            }
            else{
                ret.push_back(mpSum[i] / mpNum[i]);
            }
        }

        return ret;
    }
};