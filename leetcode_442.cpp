// leetcode 442 https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description
// 442. Find All Duplicates in an Array

#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> result;

        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) 
        {
        label:
            int v = nums[i];
            if (v > n || v == -1)
                continue;
            
            if (nums[v-1] > n)
            {
                nums[v - 1] = nums[v - 1] + 1;
                nums[i] = -1;
            }
            else
            {
                nums[i] = nums[v-1];
                nums[v-1] = n + 1;
                goto label;
            }
        }


        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == (n + 2))
                result.push_back(i+1);

            std::cout << nums[i] << " ";
        }      

        std::cout << std::endl;

        return result; 
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    // [4,3,2,7,8,2,3,1]
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    vector<int> result = (new Solution())->findDuplicates(nums);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}