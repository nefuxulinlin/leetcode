// 148. Sort List
// https://leetcode.com/problems/sort-list/#/description

#include <vector>
#include <iostream>
#include <algorithm>

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
    static bool compare(ListNode* a, ListNode* b)
    {
        return a->val < b->val;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        vector<ListNode*> sortArray;
        ListNode* iter = head;
        while (iter != NULL)
        {
            sortArray.push_back(iter);
            iter = iter->next;
        }
        sort(sortArray.begin(), sortArray.end(), this->compare);
        iter = sortArray[0]; head = iter;
        for (int i = 1; i < sortArray.size(); i++)
        {
            iter->next = sortArray[i];
            iter = iter->next;
        }
        iter->next = NULL;
        return head;
    }
};

int main(int argc, char * argv[])
{
    ListNode* root = new ListNode(3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(1);

    root = (new Solution())->sortList(root);

    while (root != NULL) {
        std::cout << root->val << " ";
        root = root->next;
    }
    std::cout << std::endl;
    return 0;
}