// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using std::vector;
using std::pair;
using std::map;

/**
 * Definition for singly-linked list.
 */ struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        map<int, int> key_cnt;
        ListNode* iter = head;
        while (iter != NULL)
        {
            if (key_cnt.find(iter->val) != key_cnt.end())
            {
                key_cnt[iter->val] ++;
            }
            else
            {
                key_cnt[iter->val] = 0;
            }
            iter = iter->next;
        }
        iter = head;
        ListNode* newHead = new ListNode(1);
        ListNode* newHeadIter = newHead;
        while (iter != NULL)
        {
            if (key_cnt[iter->val] == 0)
            {
                newHeadIter->next = iter;
                newHeadIter = iter;
            }
            iter = iter->next;
        }
        newHeadIter->next = NULL;
        newHeadIter = newHead->next;
        delete newHead;
        return newHeadIter;
    }
};

int main(int argc, char * argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    head = (new Solution())->deleteDuplicates(head);

    while (head != NULL)
    {
        std::cout << head->val << " ";
        head = head->next; 
    }
    std::cout << std::endl;
    return 0;
}