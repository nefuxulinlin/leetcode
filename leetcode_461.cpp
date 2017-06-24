// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/#/description

#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            int x = (1 << i);
            if (z & x)
                cnt++;
        }
        return cnt;
    }
};

int main(int argc, char * argv[])
{
    std::cout << (new Solution())->hammingDistance(1, 4) << std::endl;
    return 0;
}