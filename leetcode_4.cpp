// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/#/description

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:

    int find(vector<int>& nums1, vector<int>& nums2, int& iter1, int& iter2)
    {
        if (iter1 >= nums1.size())
        {
            return nums2[iter2++];
        }
        if (iter2 >= nums2.size())
        {
            return nums1[iter1++];
        }

        if (nums1[iter1] <= nums2[iter2])
        {
            return nums1[iter1++];
        }
        else
        {
            return nums2[iter2++];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sort_v;
        int mid = (nums1.size() + nums2.size()) / 2;
        int flag = (nums1.size() + nums2.size()) % 2 == 0;

        int iter1 = 0, iter2 = 0, iter3 = 0;

        while (iter3 <= mid)
        {
            sort_v.push_back(find(nums1, nums2, iter1, iter2));
            iter3++;
        }

        if (flag)
        {
            return (double)(sort_v[sort_v.size() - 1] + sort_v[sort_v.size() - 2]) / 2;
        }
        else
        {
            return (double) sort_v[sort_v.size() - 1];
        }
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(2);
    std::cout << (new Solution())->findMedianSortedArrays(nums1, nums2) << std::endl;

    vector<int> nums3, nums4;
    nums3.push_back(1);
    nums3.push_back(2);
    nums4.push_back(3);
    nums4.push_back(4);
    std::cout << (new Solution())->findMedianSortedArrays(nums3, nums4) << std::endl; 
    return 0;
}