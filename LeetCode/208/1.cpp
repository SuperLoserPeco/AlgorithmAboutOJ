#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue> 
#include <iostream>
#include <map>
#include <string>

#include <sstream>
using namespace std;

const int MAX_TREENODE = 100006;
class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        int next;
        bool tail;
    };
    Node tree[MAX_TREENODE][26];
    int cnt; 
    Trie() {
        cnt = 0;
        for(int i = 0; i < 26; i++) {
            tree[cnt][i].next = -1;
            tree[cnt][i].tail = false;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int sz = word.length();
        int cur = 0;
        for(int i = 0; i < sz; i++) {
            int now = word[i] - 'a';
            if(tree[cur][now].next == -1) {
                tree[cur][now].next = ++cnt;

                for(int j = 0; j < 26; j++) {
                    tree[cnt][j].next = -1;
                    tree[cnt][j].tail = false;
                }
            }

            if(i == sz - 1) {
                tree[cur][now].tail = true;
            }
            cur = tree[cur][now].next;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int sz = word.length();
        int cur = 0;
        for(int i = 0; i < sz; i++) {
            int now = word[i] - 'a';

            if(tree[cur][now].next == -1) {
                return false;
            }

            if(i == sz - 1) {
                return tree[cur][now].tail;
            }

            cur = tree[cur][now].next;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int sz = prefix.length();
        int cur = 0;
        for(int i = 0; i < sz; i++) {
            int now = prefix[i] - 'a';

            if(tree[cur][now].next == -1) {
                return false;
            }
            
            if(i == sz - 1) {
                return true;
            }

            cur = tree[cur][now].next;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */