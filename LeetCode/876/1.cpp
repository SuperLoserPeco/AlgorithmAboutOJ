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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }
        int sz = vec.size();
        if(sz == 0)
        {
            return NULL;
        }
        else{
            return vec[sz / 2];
        }
    }
};