// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/#/description

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            switch(nums[i])
            {
                case 0: red++; break;
                case 1: white++; break;
                case 2: blue++; break;
                default: break;
            }
        }

        for (int i = 0; i < red; i++)
            nums[i] = 0;
        for (int i = 0; i < white; i++)
            nums[i + red] = 1;
        for (int i = 0; i < blue; i++)
            nums[i + red + white] = 2;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    (new Solution())->sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    return 0;
}