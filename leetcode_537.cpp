// leet code 537. Complex Number Multiplication
// https://leetcode.com/problems/complex-number-multiplication/#/description

#include <stdio.h>
#include <iostream>
#include <sstream>

using std::string;
using std::ostringstream;

class Solution {
public:
    void parser(string a, int& left, int& right)
    {
        int left_pos_end = a.find('+');
        int right_pos_end = a.find('i');

        left = atoi(a.substr(0, left_pos_end).c_str());
        right = atoi(a.substr(left_pos_end + 1, right_pos_end).c_str());
    }

    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        parser(a, a1, b1);
        parser(b, a2, b2);

        std::cout << a1 << " " << b1 << std::endl;
        std::cout << a2 << " " << b2 << std::endl;

        // Multiplication  a1*a2 + a1*b2 + b1*a2 + b1*b2 -> a1*a2 + (a1*b2 + b1*a2)i + b1*b2*(-1) -> a1*a2 - b1*b2 + (a1*b2 + b1*a2)i

        int resultA = a1*a2 - b1*b2;
        int resultB = a1*b2 + b1*a2;

        ostringstream rA, rB;
        rA << resultA;
        rB << resultB;

        return rA.str() + "+" + rB.str() + "i"; 
    }
};

int main(int argc, char * argv[])
{
    std::cout << (new Solution)->complexNumberMultiply("1+1i", "1+1i");
}


