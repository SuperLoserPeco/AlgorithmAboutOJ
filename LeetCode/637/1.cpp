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

        Node node;
        node.cur = root;
        node.ceng = 0;
        queue<Node> Q;
        if(root != NULL)
        {
            Q.push(node);
        }
        while(!Q.empty())
        {
            Node cur = Q.front();
            cout << cur.cur->val << endl;
            Q.pop();
            while(cur.ceng >= vec.size())
            {
                vector<int> vecSub;
                vec.push_back(vecSub);
            }
            vec[cur.ceng].push_back(cur.cur->val);
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
        int _size = vec.size();
        for(int i = 0; i < _size; i++)
        {
            double sum = 0;
            for(int j = 0; j < vec[i].size(); j++)
            {
                sum += vec[i][j];
            }
            if(vec[i].size() == 0)
            {
                ret.push_back(0);
            }
            else{
                ret.push_back(sum / vec[i].size());
            }
        }

        return ret;
    }
};