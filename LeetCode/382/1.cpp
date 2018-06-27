#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* s_head;
    ListNode* s_cur;
    int num;
    Solution(ListNode* head) {
        s_head = head;
        s_cur = head;
        num = 0;
        while(s_head != NULL) {
            num++;
            s_head = s_head->next;
        }
        s_head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int times = rand() % num;
        s_cur = s_head;
        for(int i = 0; i < times; i++) {
            if(s_cur->next == NULL)
                s_cur = s_head;
            else
                s_cur = s_cur->next;
        }
        return s_cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */