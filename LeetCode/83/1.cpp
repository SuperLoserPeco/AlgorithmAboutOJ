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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* current = head->next;
        ListNode* last = head;
        map<int, bool> vis;
        vis[head->val] = true;
        while(current != NULL)
        {
            if(vis[current->val])
            {
                last->next = NULL;
                current = current->next;
            }
            else{
                vis[current->val] = true;
                last->next = current;
                last = current;
                current = current->next;
            }

        }
        return head;
    }
};

int main() {
    
    return 0;
}