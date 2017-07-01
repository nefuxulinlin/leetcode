// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/#/description

#include <vector>
#include <iostream>
#include <set>
#include <map>

using std::vector;
using std::set;
using std::map;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nums1_map;
        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
        {
            if (nums1_map.find(*it) != nums1_map.end())
                nums1_map[*it]++;
            else
                nums1_map[*it] = 1;
        }
        vector<int> result;
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++)
        {
            if (nums1_map.find(*it) != nums1_map.end()
                && nums1_map[*it] > 0)
            {
                result.push_back(*it);
                nums1_map[*it]--;
            }
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);

    nums2.push_back(2);
    nums2.push_back(2);

    vector<int> result = (new Solution())->intersect(nums1, nums2);
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}