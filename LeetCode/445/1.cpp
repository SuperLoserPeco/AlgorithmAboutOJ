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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while(l1 != NULL)
        {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        int size1 = v1.size();
        int size2 = v2.size();
        int mxSize = max(size1, size2);
        if(mxSize == 0)
        {
            return NULL;
        }
        int nextStep = 0;
        vector<int> result;
        for(int i = 0; i < mxSize; i++)
        {
            int currentBit = nextStep;
            if(i < size1)
            {
                currentBit += v1[i];
            }
            if(i < size2)
            {
                currentBit += v2[i];
            }
            result.push_back(currentBit % 10);
            nextStep = currentBit /= 10;
        }
        if(nextStep != 0)
        {
            result.push_back(nextStep);
        }
        ListNode* next = NULL;
        ListNode* ret = NULL;
        for(int i = 0; i < result.size(); i++)
        {
            ListNode* cur = new ListNode(result[i]);
            cur->next = next;
            next = cur;
            ret = cur;
        }
        return ret;
    }
};