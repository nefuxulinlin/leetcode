// 500. Keyboard Row
// https://leetcode.com/problems/keyboard-row/#/description

#include <vector>
#include <iostream>
#include <set>
#include <string>

using std::set;
using std::vector;
using std::string;

class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        set<char> key_board_line1, key_board_line2, key_board_line3;
        vector<set<char> > key_board;

        char c1[] = {'Q', 'q', 'W', 'w', 'E', 'e', 'R', 'r', 'T', 't', 'Y', 'y', 'U', 'u', 'I', 'i', 'O', 'o', 'P', 'p'};
        char c2[] = {'A', 'a', 'S', 's', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l'};
        char c3[] = {'Z', 'z', 'X', 'x', 'C', 'c', 'V', 'v', 'B', 'b', 'N', 'n', 'M', 'm'};

        for (int i = 0; i < 20; i++)
            key_board_line1.insert(c1[i]);
        for (int i = 0; i < 18; i++)
            key_board_line2.insert(c2[i]);
        for (int i = 0; i < 14; i++)
            key_board_line3.insert(c3[i]);

        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            set<char> target;
            char first = words[i].at(0);
            if (key_board_line1.find(first) != key_board_line1.end())
                target = key_board_line1;
            else if (key_board_line2.find(first) != key_board_line2.end())
                target = key_board_line2;
            else if (key_board_line3.find(first) != key_board_line3.end())
                target = key_board_line3;
            int j;
            for (j = 1; j < words[i].length(); j++)
            {
                if (target.find(words[i].at(j)) == target.end())
                    break;
            }
            if (j == words[i].length())
                result.push_back(words[i]);
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<string> words;
    words.push_back("Hello");
    words.push_back("Alaska");
    words.push_back("Dad");
    words.push_back("Peace");

    vector<string> result = (new Solution())->findWords(words);

    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    return 0;
}