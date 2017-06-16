// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/#/description

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using std::string;


class Solution {
public:
    void reverseWords(string &s) {

        reverse(s.begin(), s.end());

        int start_pos = 0, end_pos = 0, iter = 0;
        while (end_pos != string::npos)
        {
            start_pos = s.find_first_not_of(' ', end_pos);
            if (start_pos == string::npos)
                break;
            end_pos = s.find_first_of(' ', start_pos);
            string tmp;
            if (end_pos == string::npos)
            {
                tmp = s.substr(start_pos);
            }
            else
            {
                tmp = s.substr(start_pos, end_pos - start_pos);
            }
            reverse(tmp.begin(), tmp.end());
            s.replace(iter, tmp.length(), tmp);
            iter += tmp.length();
            if (end_pos != string::npos)
            {
                s.replace(iter, 1, " ");
                iter += 1;
            }
        }
        if (end_pos != string::npos && iter > 0 && s.at(iter - 1) == ' ')
            s = s.substr(0, iter - 1);
        else
            s = s.substr(0, iter);
    }
};

int main(int argc, char * argv[])
{
    string s(" 1");
    (new Solution())->reverseWords(s);
    std::cout << s << " length = " << s.length() << std::endl;
    return 0;
}