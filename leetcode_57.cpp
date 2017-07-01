// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/#/description

#include <iostream>
#include <vector>

using std::vector;

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

    // 1: orig > newInterval 0: overleap -1: orig < newInterval
    int overleap(const Interval& orig, Interval& newInterval)
    {
        if (orig.end < newInterval.start)
            return -1;
        if (orig.start > newInterval.end)
            return 1;
        
        if (orig.start <= newInterval.start)
            newInterval.start = orig.start;
        if (orig.end >= newInterval.end)
            newInterval.end = orig.end;

        return 0;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool flag = false;

        vector<Interval>::iterator it = intervals.begin();
        for (; it != intervals.end(); it++)
        {
            int cmp = overleap(*it, newInterval);
            if (cmp > 0)
            {
                result.push_back(newInterval);
                flag = true;
                break;
            }
            if (cmp < 0)
                result.push_back(*it);
        }

        for (; it != intervals.end(); it++)
        {
            result.push_back(*it);
        }
        if (flag == false)
            result.push_back(newInterval);

        return result;
    }
};

int main(int argc, char * argv[])
{
    /*
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(6,9));

    Interval newIterval(2,5);

    vector<Interval> result = (new Solution())->insert(intervals, newIterval);

    for (vector<Interval>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << (*it).start << " " << (*it).end << std::endl;
    */

    vector<Interval> intervals;
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));

    Interval newIterval(4,9);

    vector<Interval> result = (new Solution())->insert(intervals, newIterval);

    for (vector<Interval>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << (*it).start << " " << (*it).end << std::endl;

    return 0;
}