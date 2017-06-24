// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/#/description

#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>

using std::set;
using std::map;
using std::vector;
using std::string;

class Solution {
public:
    string reorder(string str)
    {
        map<char, int> c2cnt;
        for (int i = 0; i < str.length(); i++)
        {
            char c = str.at(i);
            if (c2cnt.find(c) != c2cnt.end())
            {
                c2cnt[c]++;
            }
            else
            {
                c2cnt[c] = 1;
            }
        }
        string result;
        for (map<char, int>::iterator iter = c2cnt.begin(); iter != c2cnt.end(); iter++)
        {
            for (int i = 0; i < (*iter).second; i++)
                result += (*iter).first;
        }
        return result;
    }

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > str2map;
        for (int i = 0; i < strs.size(); i++) {
            string key = reorder(strs[i]);
            if (str2map.find(key) != str2map.end())
            {
                str2map[key].push_back(strs[i]);
            }
            else
            {
                vector<string> v;
                v.push_back(strs[i]);
                str2map[key] = v;
            }
        }
        vector<vector<string> > result;
        for (map<string, vector<string> >::iterator iter = str2map.begin(); iter != str2map.end(); iter++)
        {
            result.push_back((*iter).second);
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    vector<vector<string> > result = (new Solution())->groupAnagrams(strs);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}