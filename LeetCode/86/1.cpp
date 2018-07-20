#include <vector>
#include <string>
using namespace std;

//Algorithm
//O(n^3)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//你应当保留两个分区中每个节点的初始相对位置。
    ListNode* partition(ListNode* head, int x) {

        ListNode* cur = head;
        ListNode* ret = NULL;
        ListNode* subCur = NULL;

        while(cur != NULL) {
            if(cur->next != NULL) {
                if(cur->next->val < x) {
                    ListNode* curNext = cur->next->next;
                    cur->next->next = head;

                    cur->next->next = NULL;
                    if(ret == NULL) {
                        ret = cur->next;
                        subCur = cur->next;
                    }
                    else{
                        subCur->next = cur->next;
                        subCur = cur->next;
                    }
                    cur->next = curNext;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};