// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/#/description

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        set<int> sort_set;
        for (int i = 0; i < nums.size(); i++)
        {
            sort_set.insert(nums[i]);
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            if (sort_set.find(i) == sort_set.end())
                result.push_back(i);
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    vector<int> result = (new Solution())->findDisappearedNumbers(nums);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}