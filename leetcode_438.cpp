// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

#include <vector>
#include <iostream>
#include <string>
#include <map>

using std::vector;
using std::map;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> p_map;
        for (int i = 0; i < p.length(); i++)
        {
            if (p_map.find(p.at(i)) != p_map.end())
            {
                p_map[p.at(i)]++;
            }
            else
            {
                p_map[p.at(i)] = 0;
            }
        }
    }
};

int main(int argc, char * argv[])
{
    return 0;
}