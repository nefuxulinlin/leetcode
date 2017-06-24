// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/#/description

#include <string>
#include <iostream>
#include <algorithm>

using std::string;

class Solution {
public:
    string licenseKeyFormatting(string S, int K)
    {
        if (S.length() < 1)
            return S;

        string result;
        int length, cnt = 0;

        for (int i = S.length() - 1; i >= 0; i--)
        {
            length = result.length();   
            char c = S.at(i);
            if (c >= 'A' && c <= 'Z')
                result += c;
            else if (c >= 'a' && c <= 'z')
                result += c - 'a' + 'A';
            else if (c >= '0' && c <= '9')
                result += c;
            if (length != result.length())
            {
                cnt++;
                if (cnt == K)
                {
                    result += '-';
                    cnt = 0;
                }
            }
        }
        if (result.length() > 0 && result.at(result.length() - 1) == '-')
        {
            result = result.substr(0 , result.length() - 1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char * argv[])
{
    string in("r");
    std::cout << (new Solution())->licenseKeyFormatting(in, 1) << std::endl;
    return 0;
}