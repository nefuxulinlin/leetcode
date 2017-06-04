#include <string>
#include <iostream>
#include <vector>
#include <math.h>

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


/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
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

    string toHex(int num) {
        if (num == 0)
            return string("0");

        string result("");
        string arr("0123456789abcdef");
        bool flag = false;

        for (int i = 7; i >= 0; i--) {
            int mask = 0x0000000f, v = 0;
            v = num >> (i * 4) & mask;
            if ((v) != 0 || flag == true) {
                flag = true;
                result += arr.substr((v), 1);
            }
        }
        return result;
    }

    bool repeatedSubstringPattern(string str, string prefix) {
        if (str == prefix)
            return true;
        if (str.substr(0, prefix.length()) == prefix) {
            if (str.length() < prefix.length() * 2)
                return false;
            return repeatedSubstringPattern(str.substr(prefix.length(), str.length() - prefix.length()), prefix);
        } else {
            return false;
        }
    }

    bool repeatedSubstringPattern(string str) {
        if (str.length() == 1)
            return true;

        for (int i = str.length() / 2; i >= 0; i--) {
            if (repeatedSubstringPattern(str, str.substr(0, i + 1)))
                return true;
        }
        return false;
    }

    // TOD: not complete yet.
    int guess(int num) {
        int guess = 5;
        return num == guess ? 0 : num > guess ? 1 : -1;
    }
    int guessNumber(int n) {

        int lastpos = n, lastc = 1, org = n;

        while (true) {
            int r = guess(n);
            if (r == 0)
                return n;
            if (r > 1) {
                if (lastc == 1)
                    n = n / 2;
                else
                    n = lastpos + (n - lastc) / 2;
                lastc = 1;
                lastpos = n;
            } else {
                if (lastc == -1)
                    n = n + (org - n  / 2);
                else
                    n = n + (lastpos - n) / 2;
                lastc = -1;
                lastpos = n;
            }
        }
        return n;
    }

    // TODO: not complete yet.
    int findNthDigit(int n) {

        if (n < 10) return n;

        int bit = 2, mul = 100, max = 9;

        while (max < n) {
            max += bit * mul;
            bit++;
            mul *= 10;
            // std::cout << "mul = " << mul << std::endl;
        }

        bit--;
        mul /= 10;

        // std::cout << "mul = " << mul << std::endl;

        int start = mul / 10;
        std::cout << "max = " << max << " bit = " << bit << " mul = " << mul << std::endl;
        int pos = (n - (max - bit * mul + 1)) / bit;
        int inpos = (n - (max - bit * mul + 1)) % bit;
        inpos = bit - inpos - 1;
        std::cout << "start = " << start << " pos = " << pos << " inpos = " << inpos << std::endl;

        int result = start + pos;

        while (inpos > 0) {
            result /= 10;
            inpos--;
        }
        return result % 10;
    }

    // TODO: not complete yet.
    /*vector<int> findAnagrams(string s, string p) {

        vector<int> result;
        if (s.length() < p.length()) return result;

        int count[26], tmp[26];
        memset(count, 0, sizeof(int));
        for (int i = 0; i < p.length(); i++) {
            count[p.at(i) - 'a']++;
            tmp[p.at(i) - 'a']++;
        }

        total = p.length();
        for (int i = 0; i < p.length(); i++) {
            if (tmp[s.at(i) - 'a'] != 0) {
                total--;
                tmp[s.at(i) - 'a']--;
            }
        }
        int start = 0, end = p.length() - 1;

        for (int i = p.length(); i < s.length(); i++) {
           if (total == 0) {
                result.push_back(start);

           }
        }
    }*/

    // TODO: not complete yet.
    // we can qsort nums, then pick topk return. also can optimazer it.
    // we can collect result when sort processing.
    /*vector<int> topKFrequent(vector<int>& nums, int k) {

    }*/

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int result  = 9, start = 9, tmp = n;
        while (tmp > 1) {
            result *= start;
            start--;
            tmp--;
        }
        return countNumbersWithUniqueDigits(n -1) + result;
    }

    int minMoves2(vector<int>& nums) {
        // sort(nums, 0, nums.size());
        int mid = nums.size() / 2, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += abs(nums[i] - mid);
        }
        return result;
    }

    Solution() {}

ListNode* head, *save_head;
int list_length;
int curr_length;

    Solution(ListNode* head) {
        this->head = head;
        save_head = head;

        list_length = 0;
        curr_length = 0;

        while (head) {
            list_length++;
            head = head->next;
        }
        curr_length = list_length;
    }

    int getRandom() {
        if (curr_length == 0) {
            head = save_head;
            curr_length = list_length;
        }

        int pick = rand() % curr_length;
        ListNode* tmp = head;
        while (pick > 1) {
            tmp = tmp->next;
            pick--;
        }
        int v = tmp->val;
        head->val ^= tmp->val;
        tmp->val ^= head->val;
        head->val ^= tmp->val;
        head = head->next;
        curr_length--;
        return v;
    }

    static void toStringV(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
    }

    static void toStringV(vector<struct Interval> v) {
        for (int i = 0;  i < v.size(); i++) {
            std::cout << "[" << v[i].start << "," << v[i].end << "],";
        }
    }

    static bool cmp(struct Interval v1, struct Interval v2) {
        return v1.start < v2.start;
    }

    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<Interval> idx;
        for (int i = 0; i < intervals.size(); i++) {
            idx.push_back(Interval(intervals[i].start, i));
        }

        sort(intervals.begin(), intervals.end(), cmp);
        sort(idx.begin(), idx.end(), cmp);

        toStringV(intervals);
        std::cout << std::endl;
        toStringV(idx);
        std::cout << std::endl;

        vector<int> result;
        result.resize(intervals.size());

        int i,j;
        for (i = 0; i < intervals.size(); i++) {
            for (j = i + 1; j < intervals.size(); j++) {
                if (intervals[i].end <= intervals[j].start) {
                    result[idx[i].end] = idx[j].end;
                    break;
                }
            }
            if (j == intervals.size()) result[idx[i].end] = -1;
        }
        return result;
    }

    string decodeString(string s) {

        int i = 0;
        string result("");
        vector<string> s_stack;
        vector<int> r_stack;

        while (i < s.length()) {
            if (s.at(i) >= '0' && s.at(i) <= '9') {
                string num = s.substr(i, s.find('[', i) - i);
                int repeat = atoi(num.c_str());
                r_stack.push_back(repeat);
                s_stack.push_back("[");
                i = s.find('[', i) + 1;
                std::cout << "repeate = " << repeat << std::endl;
                std::cout << "push_back : " << "[" << std::endl;
                continue;
            }
            if (s.at(i) != ']') {
                char c = s.at(i);
                s_stack.push_back(string(&c));
                std::cout << "push_back : " << c << std::endl;
            }
            else
            {
                string tmp("");
                while (true) {
                    string c = s_stack[s_stack.size() - 1];
                    std::cout << "pop_back : " << c << std::endl;
                    s_stack.pop_back();

                    if (c.at(0) != '[') {
                        tmp = c + tmp;
                    }
                    else {
                        int repeat = r_stack[r_stack.size() - 1];
                        r_stack.pop_back();
                        string r("");
                        std::cout << "pop_repeat : " << repeat << "get tmpstr = " << tmp << std::endl;

                        while (repeat) {
                            r += tmp;
                            repeat--;
                        }
                        s_stack.push_back(r);
                        std::cout << "push_back : " << tmp << std::endl;
                        break;
                    }
                }
            }
            i++;
        }

        for (i = s_stack.size() - 1; i >= 0; i--)
            result = s_stack[i] + result;

        return result;
    }

    bool validUtf8(vector<int>& data) {
        int byte2 = 0xc0, byte21 = 0x20, byte3 = 0xe0, byte31 = 0x10, byte4 = 0xf0, byte41 = 0x08, mask = 0x80, mask1 = 0x40;

        for (int i = 0; i < data.size(); i++) {
            std::cout << "loop i = " << i << std::endl;
            int t = data[i];
            std::cout << "t = " << t << endl;
            if ((t & byte2) == byte2 && !(t & byte21)) {
                std::cout << "byte2 branch" << std::endl;
                if (!((i + 1) < data.size()
                    && ((data[i+1]) & mask) && !(data[i + 1] & mask1)
                    ))
                    return false;
                i += 1;
            } else if ((t & byte3) == byte3 && !(t & byte31)) {
                std::cout << "byte3 branch" << std::endl;
                if (!((i + 2) < data.size()
                    && (data[i + 1] & mask) && !(data[i + 1] & mask1)
                    && (data[i + 2] & mask) && !(data[i + 2] & mask1)
                    )) {
                        std::cout << "return flase;" << std::endl;
                        return false;
                    }
                i += 2;
            } else if ((t & byte4) == byte4 && !(t & byte41)) {
                std::cout << "byte4 branch" << std::endl;
                if (!((i + 3) < data.size()
                    && (data[i + 1] & mask) && !(data[i + 1] & mask1)
                    && (data[i + 2] & mask) && !(data[i + 2] & mask1)
                    && (data[i + 3] & mask) && !(data[i + 3] & mask1)
                    ))
                    return false;
                i += 3;
            } else if ((t & mask)) {
                std::cout << "end branch" << std::endl;
                return false;
            }
        }
        return true;
    }

    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return 0;
    }

    string removeDuplicateLetters(string s) {
        vector<vector<int> > count;
        count.resize(26);

        for (int i = 0; i < s.length(); i++) {
            count[s.at(i) - 'a'].push_back(i);
        }

        string result("");

        int k;
        while (true) {
            k = 0;
            for (int i = 0; i < 26; i++) {
                if (count[i].size() > 0) {
                    int start;
                    for (int z = 0; z < count[i].size(); z++) {
                        if (count[i][z] != s.length()) {
                            start = count[i][z];
                            break;
                        }
                    }
                    int j;
                    for (j = 0; j < 26; j++) {
                        if (j == i) continue;
                        if (count[j].size() > 0) {
                            if (count[j][count[j].size() - 1] < start) {
                                break;
                            }
                        }
                    }
                    if (j == 26) {
                        char v[] = {'\0', '\0'};
                        v[0] = 'a' + i;
                        result += string(v);
                        count[i].clear();
                        for (int p = 0; p < 26; p++) {
                            if (count[p].size() == 0) continue;
                            for (int q = 0; q < count[p].size(); q++) {
                                if (count[p][q] < start) count[p][q] = s.length();
                                else break;
                            }
                        }
                        i = -1;
                    }
                } else {
                    k++;
                }
            }
            if (k == 26) {
                break;
            }
        }
        return result;
    }

};

int main() {

    std::cout << "case 1:" << (new Solution())->removeDuplicateLetters("bbcaac") << std::endl;

    // vector<int> nums1, nums2;
    // nums1.push_back(197); nums1.push_back(130); nums1.push_back(1);
    // std::cout << "case 1:" << (new Solution())->validUtf8(nums1) << std::endl;
    // nums2.push_back(230); nums2.push_back(145); nums2.push_back(136);
    // std::cout << "case 2:" << (new Solution())->validUtf8(nums2) << std::endl;


    // std::cout << "case 1:" << (new Solution())->decodeString("3[a]2[bc]") << std::endl;
    // std::cout << "case 1:" << (new Solution())->decodeString("3[a2[c]]") << std::endl;
    // std::cout << "case 1:" << (new Solution())->decodeString("2[abc]3[cd]ef") << std::endl;

    // vector<Interval> in;
    // in.push_back(Interval(3,4));
    // in.push_back(Interval(2,3));
    // in.push_back(Interval(1,2));
    // std::cout << "case 1:"; Solution::toStringV(((new Solution())->findRightInterval(in))); std::cout << std::endl;


    // vector<int> nums;
    // nums.push_back(1); nums.push_back(2); nums.push_back(3);
    // std::cout << "case 1:" << (new Solution())->minMoves2(nums) << std::endl;


    // std::cout << "case 1:" << (new Solution())->countNumbersWithUniqueDigits(2) << std::endl;
    // std::cout << "case 1:" << (new Solution())->countNumbersWithUniqueDigits(3) << std::endl;
    // 10, 11, 12
    // std::cout << "case 1:" << (new Solution())->findNthDigit(10) << std::endl;
    // std::cout << "case 1:" << (new Solution())->findNthDigit(11) << std::endl;
    // std::cout << "case 1:" << (new Solution())->findNthDigit(12) << std::endl;
    // std::cout << "case 1:" << (new Solution())->findNthDigit(13) << std::endl;
    // std::cout << "case 1:" << (new Solution())->findNthDigit(14) << std::endl;
    // std::cout << "case 1:" << (new Solution())->findNthDigit(15) << std::endl;

    // std::cout << "case 1:" << (new Solution())->guessNumber(10) << std::endl;
    // std::cout << "case 2:" << (new Solution())->guessNumber(20) << std::endl;

    // std::cout << "case 1:" << (new Solution())->lengthOfLongestSubstring("abcabcbb") << std::endl;
    // std::cout << "case 2:" << (new Solution())->lengthOfLongestSubstring("bbbbb") << std::endl;
    // std::cout << "case 3:" << (new Solution())->lengthOfLongestSubstring("pwwkew") << std::endl;

    // std::cout << "case 1:" << (new Solution())->addStrings("0", "0") << std::endl;
    // std::cout << "case 1:" << (new Solution())->addStrings("1", "9") << std::endl;

    // std::cout << "case 1:"; (new Solution())->toStringV((new Solution())->readBinaryWatch(1)); std::cout << std::endl;
    // std::cout << "case 1:"; (new Solution())->toStringV((new Solution())->readBinaryWatch(0)); std::cout << std::endl;

    // std::cout << "case 1:" << (new Solution())->toHex(1) << std::endl;
    // std::cout << "case 1:" << (new Solution())->toHex(-1) << std::endl;

    // std::cout << "case 1:" << ((new Solution())->repeatedSubstringPattern("abab") == true ? "true" : "false") << std::endl;
    // std::cout << "case 1:" << ((new Solution())->repeatedSubstringPattern("aaaa") == true ? "true" : "false") << std::endl;
    return 0;
}

