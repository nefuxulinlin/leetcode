// 508. Most Frequent Subtree Sum
// https://leetcode.com/problems/most-frequent-subtree-sum/#/description

#include <vector>
#include <iostream>
#include <set>
#include <map>

using std::map;
using std::set;
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
    int findFrequentTreeSum(TreeNode* root, map<int, int>& sum2cnt)
    {
        int leftSum = 0, rightSum = 0;
        if (root->left)
            leftSum = findFrequentTreeSum(root->left, sum2cnt);
        if (root->right)
            rightSum = findFrequentTreeSum(root->right, sum2cnt);
        
        int rootSum = root->val + leftSum + rightSum;

        if (sum2cnt.find(rootSum) != sum2cnt.end())
            sum2cnt[rootSum]++;
        else
            sum2cnt[rootSum] = 1;
        return rootSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
    

        map<int, int> sum2cnt;
        findFrequentTreeSum(root, sum2cnt);

        map<int, vector<int> > cnt2sum;
        for (map<int, int>::iterator iter = sum2cnt.begin(); iter != sum2cnt.end(); iter++)
        {
            int sum = (*iter).first, cnt = (*iter).second;
            if (cnt2sum.find(cnt) != cnt2sum.end())
            {
                cnt2sum[cnt].push_back(sum);
            }
            else
            {
                vector<int> sum_v;
                sum_v.push_back(sum);
                cnt2sum[cnt] = sum_v;
            }
        }
        map<int,vector<int> >::reverse_iterator iter = cnt2sum.rbegin();
        return (*iter).second;    
    }
};

int main(int argc, char * argv[])
{
    // case 1:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);

    vector<int> result = (new Solution())->findFrequentTreeSum(root);

    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    // case 2:
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(-5);

    vector<int> result2 = (new Solution())->findFrequentTreeSum(root2);
    for (int i = 0; i < result2.size(); i++)
        std::cout << result2[i] << " ";
    std::cout << std::endl;

    return 0;
}