#include <string>
#include <iostream>
#include <vector>

/*!
 * leetcode for simple question.
 */

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // code 1:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }

        string keep = "";
        int start = 0, end = 0;
        for (int i = 1; i < s.length(); i++) {
            int pos;
            if ((pos = s.substr(start, end - start + 1).find(s.at(i))) != string::npos) {
                start = start + pos + 1;
                end = i;
                if (keep.length() < (s.substr(start, end - start + 1)).length()) {
                    keep = s.substr(start, end - start + 1);
                }
            }
            else {
                end = i;
                if (keep.length() < (s.substr(start, end - start + 1).length())) {
                    keep = s.substr(start, end - start + 1);
                }
            }
        }
        return keep.length();
    }

    // code 2:
   char findTheDifference(string s, string t) {
        int keep[26];
        memset(keep, 0, sizeof(int) * 26);

        for (int i = 0; i < s.length(); i++) {
            keep[s.at(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (keep[t.at(i) - 'a'] > 0)
                keep[t.at(i) - 'a']--;
            else
                return keep[t.at(i) - 'a'];
        }
        return ' ';
    }

    //code 3:
    int sumOfLeftLeaves(TreeNode* root, int side, int& sum) {
        if (root->left == NULL && root->right == NULL) {
            if (side == 0)
                sum += root->val;
            return sum;
        }
        if (root->left != NULL) {
            sumOfLeftLeaves(root->left, 0, sum);
        }
        if (root->right != NULL) {
            sumOfLeftLeaves(root->right, 1, sum);
        }
        return sum;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root != NULL)
            sum = sumOfLeftLeaves(root, 1, sum);
        return sum;
    }

    // code 4:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                result.push_back("FizzBuzz");
                continue;
            }
            if (i % 3 == 0) {
                result.push_back("Fizz");
                continue;
            }
            if (i % 5 == 0) {
                result.push_back("Buzz");
                continue;
            }
            result.push_back(to_string(i));
        }
        return result;
    }

    // code 5:
    int firstUniqChar(string s) {
        int count[128], fpos[128];
        memset(count, 0, sizeof(int) * 128);
        memset(fpos, 0, sizeof(int) * 128);
        for (int i = 0; i < s.length(); i++) {
            if (count[s.at(i) - ' '] == 0) {
                count[s.at(i) - ' ']++;
                fpos[s.at(i) - ' '] = i;
            } else {
                count[s.at(i) - ' ']++;
            }
        }
        int result = 99999999;
        for (int i = 0; i < 128; i++) {
            if (count[i] == 1) {
                if (fpos[i] < result)
                    result = fpos[i];
            }
        }
        return result == 99999999 ? -1 : result;
    }

    // code 6:
    string addStrings(string num1, string num2) {
   #define ADD() \
    if (tmp >= 10) { \
        result = to_string(tmp % 10) + result; \
        tmp = 1; \
        } else { \
        result = to_string(tmp) + result; \
        tmp = 0; \
        }

        string result("");
        int tmp = 0, i = num1.length() - 1, j = num2.length() - 1;
        while (i >= 0 && j >=0) {
            tmp += (num1.at(i) - '0') + (num2.at(j) - '0');
            ADD();
            i--; j--;
        }
        while (i >= 0) {
            tmp += num1.at(i) - '0';
            ADD();
            i--;
        }
        while (j >= 0) {
            tmp += num2.at(j) - '0';
            ADD();
            j--;
        }
        if (tmp == 1) {
            result = to_string(tmp) + result;
        }
        return result;
    }

    // code 7:
    void readBinaryWarch(int bit, int c, int ct, int num, vector<string>& result) {
        if (c > 10) return;

        if (ct == num) {
            // 0000 0000 0011 1111
            // 0000 0011 1100 0000
            int h = 0x03c0 & bit, m = 0x003f & bit;
            h >>= 6;
            if (h <= 11 && m <= 59) {
                if (m < 10) {
                    result.push_back(to_string(h) + string(":0") + to_string(m));
                } else {
                    result.push_back(to_string(h) + string(":") + to_string(m));
                }
            }
            return;
        }

        readBinaryWarch(bit | (1 << c), c + 1, ct + 1, num, result);
        readBinaryWarch(bit, c + 1, ct, num, result);
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        int bit = 0;
        readBinaryWarch(bit, 0, 0, num, result);
        return result;
    }

    // utils:
    // print vector<string>
    void toStringV(vector<string> v) {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
    }
};

int main() {
    // std::cout << "case 1:" << (new Solution())->lengthOfLongestSubstring("abcabcbb") << std::endl;
    // std::cout << "case 2:" << (new Solution())->lengthOfLongestSubstring("bbbbb") << std::endl;
    // std::cout << "case 3:" << (new Solution())->lengthOfLongestSubstring("pwwkew") << std::endl;

    // std::cout << "case 1:" << (new Solution())->addStrings("0", "0") << std::endl;
    // std::cout << "case 1:" << (new Solution())->addStrings("1", "9") << std::endl;

    std::cout << "case 1:"; (new Solution())->toStringV((new Solution())->readBinaryWatch(1)); std::cout << std::endl;
    std::cout << "case 1:"; (new Solution())->toStringV((new Solution())->readBinaryWatch(0)); std::cout << std::endl;

    return 0;
}

