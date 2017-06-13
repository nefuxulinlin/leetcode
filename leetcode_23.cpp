// 23. Merge k Sorted Lists https://leetcode.com/problems/merge-k-sorted-lists/#/description

#include <vector>
#include <iostream>

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

    ListNode* PickNode(vector<ListNode*>& list)
    {
        int small, pos, flag = 0;

        for (int i = 0; i < list.size(); ++i)
        {
            if (list[i] != NULL)
            {
                if (flag == 0)
                {
                    small = list[i]->val;
                    pos = i;
                    flag = 1;
                }
                else
                {
                    if (small > list[i]->val)
                    {
                        small = list[i]->val;
                        pos = i;
                    }
                }
            }
        }

        if (flag == 0)
        {
            return NULL;
        }

        ListNode* result = list[pos];
        list[pos] = list[pos]->next;

        return result;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<ListNode*> copy = lists;
        ListNode* root = new ListNode(0);
        ListNode* cursor = root;

        while (true)
        {
            ListNode* small = PickNode(copy);
            if (small == NULL)
                break;

            ListNode* item = new ListNode(small->val);
            cursor->next = item;
            cursor = item;
        }

        return root->next;
    }
};

int main(int argc, char * argv[])
{
    ListNode* root1 = new ListNode(1);
    ListNode* root2 = new ListNode(3);
    ListNode* root3 = new ListNode(2);

    vector<ListNode*> lists;
    lists.push_back(root1);
    lists.push_back(root2);
    lists.push_back(root3);

    ListNode* sort = (new Solution())->mergeKLists(lists);

    while (sort != NULL)
    {
        std::cout << sort->val << " ";
        sort = sort->next;
    }
    std::cout << std::endl;

    return 0;
}