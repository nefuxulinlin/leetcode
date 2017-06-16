// 414. Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/#/description

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        set<int> sort;
        for (int i = 0; i < nums.size(); i++)
        {
            sort.insert(nums[i]);
        }
        set<int>::iterator iter = sort.end();
        if (sort.size() < 3)
            return *(--iter);
        --iter;
        --iter;
        --iter;
        return *iter;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);

    std::cout << (new Solution())->thirdMax(nums) << std::endl; 
    return 0;
}