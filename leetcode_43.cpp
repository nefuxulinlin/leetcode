// 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/#/description

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> 

using std::string;
using std::vector;

class Solution {
public:

    string single_product(string num1, int c, int tenCnt)
    {
        if (c == 0)
            return "";

        int flag = 0;
        string result;
        while (tenCnt > 0)
        { 
            tenCnt--;   
            result += "0";
        }

        for (int i = num1.length() - 1; i >= 0; i--)
        {
            int cur = ((num1.at(i) - '0') * c + flag);
            result += cur % 10 + '0';
            flag = cur / 10;

        }
        if (flag > 0)
            result += flag + '0';
        return result;
    }

    string plus(vector<string> single_arr, int max)
    {
        int flag = 0;
        string result;

        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < single_arr.size(); j++)
            {
                string tmp = single_arr[j];
                if (i < tmp.length())
                {
                    flag += tmp.at(i) - '0';   
                }
            }
            result += ((flag % 10) + '0');
            flag /= 10;
        }
        if (flag > 0)
            result += flag + '0';

        return result;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
            
        vector<string> single_arr;
        int tenCnt = 0, max_length = 0;

        for (int i = num2.length() - 1; i >= 0; i--, tenCnt++)
        {
            string single_res = single_product(num1, num2.at(i) - '0', tenCnt);
            max_length = max_length > single_res.length() ? max_length : single_res.length();
            if (single_res != "")
                single_arr.push_back(single_res);
        }

        string result = plus(single_arr, max_length);

        reverse(result.begin(),result.end());
        return result;
    }
};

int main(int argc, char * argv[])
{
    string num1 = "1234";
    string num2 = "1234";

    std::cout << (new Solution())->multiply(num1, num2) << std::endl;
    return 0;
}