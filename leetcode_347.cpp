// leetcode 347 https://leetcode.com/problems/top-k-frequent-elements/#/description
// 347. Top K Frequent Elements

#include <iostream>
#include <set>
#include <map>
#include <vector>

using std::set;
using std::map;
using std::vector;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> value_cnt;
        set<int> sort_cnt;
        vector<int> result;
        map<int, vector<int> > cnt_value;

        for (int i = 0; i < nums.size(); i++)
        {
            if (value_cnt.find(nums[i]) == value_cnt.end())
            {
                value_cnt[nums[i]] = 1;
            }
            else
            {
                value_cnt[nums[i]]++;
            }
        }

        for (map<int, int>::iterator iter = value_cnt.begin(); iter != value_cnt.end(); iter++)
        {
            sort_cnt.insert((*iter).second);

            if (cnt_value.find((*iter).second) == cnt_value.end())
            {
                vector<int> value;
                value.push_back((*iter).first);
                cnt_value.insert(make_pair((*iter).second, value));
            }
            else
            {
                cnt_value[(*iter).second].push_back((*iter).first);
            }
        }

        int count = 0;

        set<int>::iterator iter = sort_cnt.end();
        iter--;

        do
        {
            int cnt = *iter;

            // std::cout << "cnt = " << cnt << std::endl;

            vector<int> v = cnt_value[cnt];
            for (int i = 0; i < v.size(); i++)
            {
                if (count < k)
                {
                    result.push_back(v[i]);
                    count++;
                }
                else
                    return result;
            }
            iter--;
        }
        while (true);

        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);

    vector<int> result = (new Solution())->topKFrequent(nums, 3);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}