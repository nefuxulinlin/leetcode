// 507. Perfect Number
// https://leetcode.com/problems/perfect-number/#/description

#include <iostream>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int result = 0, i;
        for (i = 2; i * i < num; i++)
        {
            if ((num % i) == 0)
            {
                std::cout << "i = " << i << std::endl;
                result += i + num / i;
                if (result > num)
                    return false;
            }
        }
        if (i * i == num)
            result += i;
        result++;

        if (result != num)
            return false;
        return true;
    }
};

int main(int argc, char * argv[])
{
    std::cout << (new Solution())->checkPerfectNumber(28) << std::endl;
    return 0;
}

