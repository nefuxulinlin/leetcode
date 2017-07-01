// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/#/description

#include <iostream>
#include <set>
#include <vector>

using std::vector;
using std::set;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> sort_nums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                sort_nums.insert(nums[i]);
        }
        if (sort_nums.size() == 0)
            return 1;
        if (sort_nums.size() == 1)
        {
            set<int>::iterator iter = sort_nums.begin();
            if (*iter == 1)
                return 2;
            else
                return 1;
        }
        set<int>::iterator iter = sort_nums.begin();
        int pre = *iter;
        iter++;
        if (pre != 1)
            return 1;
        for (; iter != sort_nums.end(); iter++)
        {
            if (pre == *iter || pre == (*iter) - 1)
            {
                pre = *iter;
            }
            else
            {
                return pre + 1;
            }
        }
        return pre + 1;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    std::cout << (new Solution())->firstMissingPositive(nums) << std::endl;
    return 0;
}