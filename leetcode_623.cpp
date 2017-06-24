// 623. Add One Row to Tree
// https://leetcode.com/contest/leetcode-weekly-contest-37/problems/add-one-row-to-tree/

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

    void addOneRow(TreeNode* root, int v, int d, int curdep)
    {
        if (curdep == d - 1)
        {
            // if (root->left)
            {
                TreeNode* node = new TreeNode(v);
                node->left = root->left;
                root->left = node;
            }
            // if (root->right)
            {
                TreeNode* node = new TreeNode(v);
                node->right = root->right;
                root->right = node;
            }
            return ;
        }
        if (root->left)
            addOneRow(root->left, v, d, curdep + 1);
        if (root->right)
            addOneRow(root->right, v, d, curdep + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        addOneRow(root, v, d, 1);
        return root;
    }
};

int main(int argc, char * argv[])
{
    return 0;
}