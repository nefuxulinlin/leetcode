// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/#/description

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
    void pathSum_travel(TreeNode* root, int target, vector<int> result, int sum, vector<vector<int> >& finalRet)
    {
        if (root == NULL) return;
        sum += root->val;
        result.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == target)
        {
            finalRet.push_back(result);
        }
        if (root->left != NULL)
            pathSum_travel(root->left, target, result, sum, finalRet);
        if (root->right != NULL)
            pathSum_travel(root->right, target, result, sum, finalRet);
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int> > finalRet;
        vector<int> result;
        pathSum_travel(root, sum, result, 0, finalRet);
        return finalRet;    
    }
};

int main(int argc, char * argv[])
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector<vector<int> > finalRet = (new Solution())->pathSum(root, 22);

    for (int i = 0; i < finalRet.size(); i++)
    {
        for (int j = 0; j < finalRet[i].size(); j++)
        {
            std::cout << finalRet[i][j] << "->";
        }
        std::cout << std::endl;
    }
    return 0;
}