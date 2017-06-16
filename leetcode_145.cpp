// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/#/description

#include <iostream>
#include <stdio.h>
#include <vector>

using std::vector;

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
    void postorderTraversal(TreeNode* root, vector<int>& result)
    {
        if (root == NULL) return;

        if (root->left != NULL)
            postorderTraversal(root->left, result);
        if (root->right != NULL)
            postorderTraversal(root->right, result);

        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};

int main(int argc, char * argv[])
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = (new Solution())->postorderTraversal(root);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    
    return 0;
}