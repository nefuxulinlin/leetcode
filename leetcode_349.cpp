// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/#/description

#include <vector>
#include <iostream>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> set_1, set_2;
        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
        {
            set_1.insert(*it);            
        }
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++)
        {
            if (set_1.find(*it) != set_1.end())
                set_2.insert(*it);
        }
        vector<int> result;
        for (set<int>::iterator it = set_2.begin(); it != set_2.end(); it++)
        {
            result.push_back(*it);
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);

    vector<int> result = (new Solution())->intersection(nums1, nums2);

    for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}


