// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/#/description

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

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

    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        if (intervals.size() <= 1)
            return intervals;

        map<int, vector<Interval> > interval_map;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (interval_map.find(intervals[i].start) != interval_map.end())
            {
                interval_map[intervals[i].start].push_back(intervals[i]);
            }
            else
            {
                vector<Interval> tmp;
                tmp.push_back(intervals[i]);
                interval_map[intervals[i].start] = tmp;
            }
        }

        intervals.clear();
        for (map<int, vector<Interval> >::iterator it = interval_map.begin();
            it != interval_map.end(); it++)
        {
            vector<Interval> tmp = (*it).second;
            for (int i = 0; i < tmp.size(); i++)
                intervals.push_back(tmp[i]);
        }
        
        Interval left = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            int cmp = overleap(left, intervals[i]);
            // assert(cmp <= 0);
            if (cmp != 0)
            {
                result.push_back(left);
            }
            left = intervals[i];
        }
        result.push_back(left);
        return result;
    }
};

int main(int argc, char * argv[])
{
    /*
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));

    vector<Interval> result = (new Solution())->merge(intervals);

    for (vector<Interval>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << (*it).start << " " << (*it).end << std::endl;
    */

    vector<Interval> intervals;
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(4,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,9));
    intervals.push_back(Interval(1,10));

    vector<Interval> result = (new Solution())->merge(intervals);

    for (vector<Interval>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << (*it).start << " " << (*it).end << std::endl;

    return 0;
}


