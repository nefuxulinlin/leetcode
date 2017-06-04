// leetcode 513 https://leetcode.com/problems/find-bottom-left-tree-value/#/description
// Find Bottom Left Tree Value

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
using std::pair;
using std::make_pair;

class Solution {
public:

    void findBottomLeftValue(TreeNode* root, vector<pair<int, int> >& value, int level)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (value.size() == 0)
            {
                value.push_back(make_pair(level, root->val));
            }
            else
            {
                if (value.back().first < level)
                {
                    value.back().first = level;
                    value.back().second = root->val;
                }
            }
            return;
        }

        if (root->left != NULL)
            findBottomLeftValue(root->left, value, level + 1);
        if (root->right != NULL)
            findBottomLeftValue(root->right, value, level + 1);
        
        return;      
    }

    int findBottomLeftValue(TreeNode* root) {
        vector<pair<int, int> > value;
        findBottomLeftValue(root, value, 0);
        return value.back().second;
    }
};

int main(int argc, char * argv[])
{
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::cout << (new Solution())->findBottomLeftValue(root) << std::endl; 
    
    return 0;
}