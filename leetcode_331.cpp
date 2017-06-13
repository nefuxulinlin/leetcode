// 331. Verify Preorder Serialization of a Binary Tree
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/#/description

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::pair;
using std::string;

class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        if (preorder == "#") return true;

        vector<int> tree;
        int pos = 0, i = 0;
        do
        {
            if (i == preorder.length() || preorder.at(i) == ',')
            {
                string sub = preorder.substr(pos, i - pos);

                if (sub == "#")
                {
                    if (tree.size() == 0)
                        return false;
                    do {
                        (tree.back())--;
                        if (tree.back() == 0) tree.pop_back();
                        else break;
                    } while (tree.size() > 0);
                }
                else
                {
                    if (pos != 0 && tree.size() == 0) return false;
                    tree.push_back(2);
                }
                pos = i + 1;
            }
            i++;
        } while (i <= preorder.length());

        if (tree.size() == 0)
            return true;
        else
            return false;
    }
};

int main(int argc, char * argv[])
{
    // std::cout << "9,3,4,#,#,1,#,#,2,#,6,#,#" << " -> " << (new Solution())->isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << std::endl;
    // std::cout << "1,#" << " -> " << (new Solution())->isValidSerialization("1,#") << std::endl; 
    // std::cout << "9,#,#,1" << " -> " << (new Solution())->isValidSerialization("9,#,#,1") << std::endl;
    std::cout << "9,3,4,#,#,1,#,#,#,2,#,6,#,#" << " -> " << (new Solution())->isValidSerialization("9,3,4,#,#,1,#,#,#,2,#,6,#,#") << std::endl;
    return 0;
}


