// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/#/description

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    static bool compare(int a, int b)
    {
        return a > b;
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), this->compare);
        return nums[k - 1];
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);

    std::cout << (new Solution())->findKthLargest(nums, 2) << std::endl;
    return 0;
}