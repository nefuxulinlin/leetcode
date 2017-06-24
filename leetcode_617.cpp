// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/#/description

#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = NULL;
        if (t1 != NULL && t2 != NULL)
        {
            root = new TreeNode((t1->val + t2->val));
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        }
        else if (t1 != NULL)
            root = t1;
        else
            root = t2;

        return root;
    }
};

void print(TreeNode* root)
{
    if (root)
        std::cout << root->val << " ";
    if (root->left)
        print(root->left);
    if (root->right)
        print(root->right);
}

int main(int argc, char * argv[])
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->left = new TreeNode(7);

    TreeNode* newRoot = (new Solution())->mergeTrees(t1, t2);

    print(newRoot);

    std::cout << std::endl;

    return 0;
}