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

class MapSum {
private:
    /** Initialize your data structure here. */
    class Trie{
        struct Node{
            bool isExist;
            int val;
            Node* ch[26];
        };
        Node* root;
        public:
        Trie()
        {
            cout << "struct" << endl;
            root = new Node();
            root->val = 0;
            root->isExist = false;
        }

        bool Insert(string s, int val)
        {
            int sz = s.length();
            Node* current = root;
            for(int i = 0; i < sz; i++)
            {
                int now = s[i] - 'a';
                if(current->ch[now] == NULL)
                {
                    current->ch[now] = new Node();
                }
                current = current->ch[now];
            }
            if(current->isExist)
            {
                current->val = val;
                return true;
            }
            else{
                current->isExist = true;
                current->val = val;
                return false;
            }
        }

        int Sum(string prefix)
        {
            int sz = prefix.length();
            Node* current = root;
            for(int i = 0; i < sz; i++)
            {
                int now = prefix[i] - 'a';
                if(current->ch[now] == NULL)
                {
                    return 0;
                }
                current = current->ch[now];
            }
            int sum = 0;
            queue<Node*> Q;
            Q.push(current);
            while(!Q.empty())
            {
                Node* now = Q.front();
                Q.pop();
                if(now->isExist)
                {
                    sum += now->val;
                }
                for(int i = 0; i < 26; i++)
                {
                    if(now->ch[i] != NULL)
                    {
                        Q.push(now->ch[i]);
                    }
                }
            }
            return sum;
        }
    } trie;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        trie.Insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.Sum(prefix);
    }
};


int main() {
    MapSum s;
    return 0;
}