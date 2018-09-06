#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>

#include <sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);

        string ret = "";
        if(root == NULL) {
            ret = ret + "null";
            return ret;
        }
        else {
            stringAddInt(ret, root->val);
        }

        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            Q.pop();
            if(cur->left == NULL) {
                ret += ",null";
            }
            else {
                ret += ",";
                stringAddInt(ret, cur->left->val);
                Q.push(cur->left);
            }

            if(cur->right == NULL) {
                ret += ",null";
            }
            else {
                ret += ",";
                stringAddInt(ret, cur->right->val);
                Q.push(cur->right);
            }
        }
        return ret;
    }//

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp = data;
        vector<string> strList = split(temp, ",");

        TreeNode* root = NULL;
        if(strList.size() == 0 || strList[0] == "null") return root;
        root = new TreeNode(stringToInt(strList[0]));
        cout << strList[0] << endl;
        cout << root->val << endl;
        queue<TreeNode*> Q;
        Q.push(root);
        for(int i = 1; i < strList.size(); i += 2) {
            if(Q.empty()) break;
            TreeNode* cur = Q.front();
            Q.pop();
            if(strList[i] == "null") {
                cur->left = NULL;
            }
            else {
                cur->left = new TreeNode(stringToInt(strList[i]));
                Q.push(cur->left);
            }
            if(strList[i + 1] == "null") {
                cur->right = NULL;
            }
            else {
                cur->right = new TreeNode(stringToInt(strList[i + 1]));
                Q.push(cur->right);
            }
        }
        return root;
    }

    int stringToInt(string s) {
        istringstream is(s); //构造输入字符串流，流的内容初始化为“12”的字符串 
        int i; 
        is >> i;
        return i;
    }

    void stringAddInt(string& s, int a) {
        
        stringstream ss;
        ss << a;
        string temp;
        ss >> temp;
        s = s + temp;
    }

    vector<string>  split(const string& str,const string& delim) { //将分割后的子字符串存储在vector中
        vector<string> res;
        if("" == str) return  res;
        
        string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
        size_t pos;
        size_t size = strs.size();
    
        for (int i = 0; i < size; ++i) {
            pos = strs.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
            if( pos < size) { //如果查找到，如果没有查找到分隔符，pos为string::npos
                string s = strs.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
                res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
                i = pos + delim.size() - 1;
            }
            
        }
        return res;	
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));