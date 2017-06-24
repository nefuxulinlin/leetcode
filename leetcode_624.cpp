// 624. Maximum Distance in Arrays
// https://leetcode.com/contest/leetcode-weekly-contest-37/problems/maximum-distance-in-arrays/

#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    int maxDistance(vector<vector<int> >& arrays) {
        
        int dis = 0;

        for (int i = 0; i < arrays.size(); i++)
        {
            for (int j = 0; j < arrays.size(); j++)
            {
                if (i == j) continue;
                dis = abs(arrays[i][0] - arrays[j][arrays[j].size() - 1]) > dis
                    ? abs(arrays[i][0] - arrays[j][arrays[j].size() - 1]) : dis;
            }
        }
        return dis;
    }
};

int main(int argc, char * argv[])
{
    vector<int> array1, array2, array3;
    array1.push_back(1);
    array1.push_back(2);
    array1.push_back(3);

    array2.push_back(4);
    array2.push_back(5);

    array3.push_back(1);
    array3.push_back(2);
    array3.push_back(3);

    vector<vector<int> > arrays;
    arrays.push_back(array1);
    arrays.push_back(array2);
    arrays.push_back(array3);

    std::cout << (new Solution())->maxDistance(arrays) << std::endl;

    return 0;
}