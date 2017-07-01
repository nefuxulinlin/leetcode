// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, vector<int> > map_idx;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (map_idx.find(numbers[i]) != map_idx.end())
            {
                map_idx[numbers[i]].push_back(i);
            }
            else
            {
                vector<int> tmp;
                tmp.push_back(i);
                map_idx[numbers[i]] = tmp;
            }
        }

        vector<int> result;
        for (int i = 0; i < numbers.size(); i++)
        {
            int need = target - numbers[i];
            if (map_idx.find(need) != map_idx.end())
            {
                if (map_idx[need].size() == 1 && map_idx[need][0] == i)
                    continue;
                if (map_idx[need].size() == 1)
                {
                    result.push_back(i+1);
                    result.push_back(map_idx[need][0] + 1);
                    break;
                }
                result.push_back(i + 1);
                result.push_back(map_idx[need][1] + 1);
                break;
            }
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    vector<int> result = (new Solution())->twoSum(nums, 9);

    if (result.size() == 2)
        std::cout << result[0] << " " << result[1] << std::endl;
    else
        std::cout << "not found result" << std::endl;
    return 0;
}