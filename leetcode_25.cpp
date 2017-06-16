// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/#/description

#include <iostream>
#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 */ struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseGroup(vector<ListNode*> v, int i, int k)
    {
        ListNode* head = v[i + k - 1];
        for (int j = i + k - 2; j >= i; j--)
        {
            head->next = v[j];
            head = v[j];
        }
        head->next = NULL;
        return v[i + k - 1];
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1)
            return head;

        vector<ListNode*> vSplit;
        ListNode* iter = head;
        while (iter != NULL)
        {
            vSplit.push_back(iter);
            iter = iter->next;
        }
        if (vSplit.size() < k)
            return head;

        head = reverseGroup(vSplit, 0, k);
        for (int i = k; i < vSplit.size(); i += k)
        {
            if ((i + k) <= vSplit.size())
            {
                vSplit[i - k]->next = reverseGroup(vSplit, i, k);
            }
            else
            {
                std::cout << " i = " << i << " k = " << k << " vSplit.size() = " << vSplit.size() << std::endl;
                vSplit[i - k]->next = vSplit[i];
            }
        }
        return head;
    }
};

int main(int argc, char * argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    head = (new Solution())->reverseKGroup(head, 2);
    while (head != NULL)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
    return 0;
}