// 628. Maximum Product of Three Numbers
// https://leetcode.com/contest/leetcode-weekly-contest-38/problems/maximum-product-of-three-numbers/

#include <iostream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using std::set;
using std::vector;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> sort_num1, sort_num2;
        if (nums.size() == 3)
        {
            return nums[0] * nums[1] * nums[2];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                sort_num1.push_back(nums[i]);
            else
                sort_num2.push_back(nums[i]);
        }
        sort(sort_num1.begin(), sort_num1.end());
        sort(sort_num2.begin(), sort_num2.end());

        int result;
        if (sort_num1.size() == 0)
        {
            vector<int>::reverse_iterator iter = sort_num2.rbegin();
            result = *iter;
            result *= *(++iter);
            result *= *(++iter);
            return result;
        }
        else if (sort_num2.size() == 0 || sort_num2.size() == 1)
        {
            vector<int>::reverse_iterator iter = sort_num1.rbegin();
            result = *iter;
            result *= *(++iter);
            result *= *(++iter);
            return result;  
        }
        else if (sort_num1.size() == 1)
        {
            vector<int>::iterator iter = sort_num2.begin();
            result = *iter;
            result *= *(++iter);
            result *= *(sort_num1.begin());
            return result;
        }
        else
        {
            int negetive;
            vector<int>::iterator iter = sort_num2.begin();
            negetive = *iter;
            negetive *= *(++iter);
            negetive *= *(sort_num1.rbegin());

            int positvie;
            vector<int>::reverse_iterator iter1 = sort_num1.rbegin();
            positvie = *iter1;
            positvie *= *(++iter1);
            positvie *= *(++iter1);
            return negetive > positvie ? negetive : positvie;
        }
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    // nums.push_back(60);

    std::cout << (new Solution())->maximumProduct(nums) << std::endl;
    return 0;
}