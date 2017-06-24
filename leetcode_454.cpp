// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/#/description

#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;

class Solution {
public:

    map<int, int> getMap(vector<int> v)
    {
        map<int, int> result;
        for (int i = 0; i < v.size(); i++)
        {
            if (result.find(v[i]) == result.end())
            {
                result[v[i]] = 1;
            }
            else
            {
                result[v[i]]++;
            }
        }
        return result;
    }

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        vector<map<int,  int> > vector4map4cnt;

        vector4map4cnt.push_back(getMap(A));
        vector4map4cnt.push_back(getMap(B));
        vector4map4cnt.push_back(getMap(C));
        vector4map4cnt.push_back(getMap(D));

        map<int, int> map4cnt1, map4cnt2;

        int result = 0;
        for (map<int, int>::iterator iter = vector4map4cnt[0].begin(); iter != vector4map4cnt[0].end(); iter++)
        {
            int c1 = (*iter).first, cnt1 = (*iter).second;
            for (map<int, int>::iterator iter = vector4map4cnt[1].begin(); iter != vector4map4cnt[1].end(); iter++)
            {
                int c2 = (*iter).first, cnt2 = (*iter).second;
                if (map4cnt1.find(c1 + c2) != map4cnt1.end())
                    map4cnt1[c1 + c2] += cnt1 * cnt2;
                else
                    map4cnt1[c1 + c2] = cnt1 * cnt2;
            }
        }

        for (map<int, int>::iterator iter = vector4map4cnt[2].begin(); iter != vector4map4cnt[2].end(); iter++)
        {
            int c1 = (*iter).first, cnt1 = (*iter).second;
            for (map<int, int>::iterator iter = vector4map4cnt[3].begin(); iter != vector4map4cnt[3].end(); iter++)
            {
                int c2 = (*iter).first, cnt2 = (*iter).second;
                if (map4cnt2.find(c1 + c2) != map4cnt2.end())
                    map4cnt2[c1 + c2] += cnt1 * cnt2;
                else
                    map4cnt2[c1 + c2] = cnt1 * cnt2;
            }
        }

        for (map<int, int>::iterator iter = map4cnt1.begin(); iter != map4cnt1.end(); iter++)
        {
            int c1 = (*iter).first, cnt1 = (*iter).second;
            int target = 0 - c1;
            if (map4cnt2.find(target) != map4cnt2.end())
            {
                result += cnt1 * map4cnt2[target];
            }
        }

        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> A, B, C, D;
    A.push_back(1);
    A.push_back(2);
    B.push_back(-2);
    B.push_back(-1);
    C.push_back(-1);
    C.push_back(2);
    D.push_back(0);
    D.push_back(2);

    std::cout << (new Solution())->fourSumCount(A, B, C, D) << std::endl;
    return 0;
}