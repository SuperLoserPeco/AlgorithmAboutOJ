/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(ListNode* a, ListNode* b) {
    return a->val < b->val;
}

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vecList;
        int sz = lists.size();
        for(int i = 0; i < sz; i++) {
            ListNode* current = lists[i];
            while(current) {
                vecList.push_back(current);
                current = current->next;
            }
        }
        sort(vecList.begin(), vecList.end(), cmp);
        sz = vecList.size();
        vecList.push_back(NULL);
        for(int i = 0; i < sz; i++) {
            vecList[i]->next = vecList[i + 1];
        }
        return vecList[0];
    }
};