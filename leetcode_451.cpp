// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/#/description

#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>


using std::string;
using std::map;
using std::set;
using std::vector;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> s_map;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.at(i);
            if (s_map.find(c) != s_map.end())
            {
                s_map[c]++;
            }
            else
            {
                s_map[c] = 1;
            }
        }
        map<int, vector<char> > c_map;
        for (map<char, int>::iterator iter = s_map.begin(); iter != s_map.end(); iter++)
        {
            int cnt = (*iter).second;
            if (c_map.find(cnt) != c_map.end())
            {
                c_map[cnt].push_back((*iter).first);
            }
            else
            {
                vector<char> v;
                v.push_back((*iter).first);
                c_map[cnt] = v;
            }
        }

        string result;
        for (map<int, vector<char> >::iterator iter = c_map.begin(); iter != c_map.end(); iter++)
        {
            int cnt = (*iter).first;
            vector<char> v = (*iter).second;
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < cnt; j++)
                {
                    result += v[i];
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char * argv[])
{
    std::cout << (new Solution())->frequencySort("tree") << std::endl;
    std::cout << (new Solution())->frequencySort("cccaaa") << std::endl;
    std::cout << (new Solution())->frequencySort("Aabb") << std::endl;

    return 0;
}