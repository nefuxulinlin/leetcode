// 599. Minimum Index Sum of Two Lists
// https://leetcode.com/problems/minimum-index-sum-of-two-lists/#/description

#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> map1, map2;
        for (int i = 0; i < list1.size(); i++)
        {
            if (map1.find(list1[i]) == map1.end())
                map1[list1[i]] = i;
        }

        int dist = INT_MAX;
        vector<string> result;

        for (int i = 0; i < list2.size(); i++)
        {
            if (map1.find(list2[i]) != map1.end())
            {
                if (dist > map1[list2[i]] + i)
                {
                    dist = map1[list2[i]] + i;
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if (dist == map1[list2[i]] + i)
                {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<string> list1, list2;
    list1.push_back("Shogun");
    list1.push_back("Tapioca Express");
    list1.push_back("Burger King");
    list1.push_back("KFC");

    list2.push_back("Piatti");
    list2.push_back("The Grill at Torrey Pines");
    list2.push_back("Hungry Hunter Steakhouse");
    list2.push_back("Shogun");
    
    vector<string> result = (new Solution())->findRestaurant(list1, list2);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}






