// leetcode 445 https://leetcode.com/problems/add-two-numbers-ii/#/description
// 445. Add Two Numbers II

#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode*> left;
        vector<ListNode*> right;

        ListNode* iter = l1;
        while(iter != NULL)
        {
            left.push_back(iter);
            iter = iter->next;
        }
        iter = l2;
        while (iter != NULL)
        {
            right.push_back(iter);
            iter = iter->next;
        }
        
        int leftCnt = left.size();
        int rightCnt = right.size();
        ListNode* result = NULL;
        int flag = 0;

#define ADD_TO_RESULT() \
    ListNode* newNode = new ListNode(flag % 10); \
    flag /= 10; \
    newNode->next = result; \
    result = newNode;

        while (left.size() != 0 && right.size() != 0)
        {
            ListNode* numleft = left.back();
            ListNode* numright = right.back();
            left.pop_back();
            right.pop_back();
            flag = numleft->val + numright->val + flag;
            
            ADD_TO_RESULT();    
        }

#define PRODUCE_LEFT_LIST(left) \
        while (left.size() != 0) \
        { \
            flag += (left.back())->val; \
            left.pop_back(); \
            ADD_TO_RESULT(); \
        }

        PRODUCE_LEFT_LIST(left);
        PRODUCE_LEFT_LIST(right);
        
        if (flag > 0)
        {
             ADD_TO_RESULT();
        }

        return result;
    }
};

int main(int argc, char * argv[])
{
    ListNode* leftHead = new ListNode(7);
    leftHead->next = new ListNode(2);
    leftHead->next->next = new ListNode(4);
    leftHead->next->next->next = new ListNode(3);

    ListNode* rightHead = new ListNode(5);
    rightHead->next = new ListNode(6);
    rightHead->next->next = new ListNode(4);

    ListNode* result = (new Solution())->addTwoNumbers(leftHead, rightHead);

    while (result != NULL)
    {
        std::cout << result->val << " ";
        result = result->next;
    }    

    std::cout << std::endl;

    return 0;
}



