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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<ListNode*> vecList;

        ListNode* current = l1;
        while(current) {
            vecList.push_back(current);
            current = current->next;
        }
        
        current = l2;
        while(current) {
            vecList.push_back(current);
            current = current->next;
        }

        sort(vecList.begin(), vecList.end(), cmp);
        int sz = vecList.size();
        vecList.push_back(NULL);
        for(int i = 0; i < sz; i++) {
            vecList[i]->next = vecList[i + 1];
        }
        return vecList[0];
    }
};