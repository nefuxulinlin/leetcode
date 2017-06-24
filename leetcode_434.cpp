// 434. Number of Segments in a String
// https://leetcode.com/problems/number-of-segments-in-a-string/#/description

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int countSegments(string s) {
        int result = 0, start = 0;
        while (true)
        {
            int end = s.find_first_not_of(' ', start);
            if (end == string::npos)
                break;
            result++;
            start = end;
            end = s.find_first_of(' ', start);
            if (end == string::npos)
                break;
            start = end;
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    std::cout << (new Solution())->countSegments("Hello, my name is John") << std::endl;
    return 0;
}