// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/#/description

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int i = ((nums.size() % 2) == 0) ? nums.size() / 2 - 1 : nums.size() / 2, j = nums.size() - 1;
        int stop = i;
        vector<int> result;
        while (j > stop)
        {
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            i--;
            j--;
        }
        if ((nums.size() % 2) == 1)
            result.push_back(nums[i]);
        nums = result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    // nums.push_back(1);
    // nums.push_back(1);
    (new Solution())->wiggleSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}