// leetcode 515 https://leetcode.com/problems/find-largest-value-in-each-tree-row/#/description
// 515. Find Largest Value in Each Tree Row

#include <stdio.h>
#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using std::vector;

class Solution {
public:
    void largestValues(TreeNode* root, vector<int>& result, int level)
    {
        if (level == result.size())
        {
            result.push_back(root->val);
        }
        else
        {
            if (result[level] < root->val)
                result[level] = root->val;
        }

        if (root->left)
            largestValues(root->left, result, level + 1);
        if (root->right)
            largestValues(root->right, result, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root)
            largestValues(root, result, 0);
        return result;
    }
};


int main(int argc, char * argv[])
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);
    
    vector<int> result = (new Solution())->largestValues(root);

    for (int i = 0 ; i < result.size(); i++)
    {
        std::cout << result[i] << " ";        
    }

    std::cout << std::endl;

    return 0;
}