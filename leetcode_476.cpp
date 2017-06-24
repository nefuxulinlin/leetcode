// 476. Number Complement
// https://leetcode.com/problems/number-complement/#/description

#include <iostream>

class Solution {
public:
    int findComplement(int num) {
        int result = 0, i = 0;
        for (i = sizeof(int) * 8; i >= 0; i--)
        {
            if ((num & (1 << i))) 
            {
                break;
            }
        }
        for (; i >= 0; i--)
        {
            if ((num & (1 << i)) == 0)
            {
                result |= (1 << i);
            }
            else
            {
                continue;
            }
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    std::cout << (new Solution())->findComplement(32) << std::endl;
    // std::cout << (new Solution())->findComplement(1) << std::endl;
    return 0;
}