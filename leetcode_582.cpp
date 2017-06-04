// leetcode 528 https://leetcode.com/problems/kill-process/#/description
// 582. Kill Process

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int count = pid.size();
        map<int, vector<int> > ppid_pid;
        vector<int> result;

        for (int i = 0; i < count; i++)
        {
            if (ppid_pid.find(ppid[i]) == ppid_pid.end())
            {
                vector<int> pid_array;
                pid_array.push_back(pid[i]);
                ppid_pid.insert(make_pair(ppid[i], pid_array));
            }
            else
            {
                ppid_pid[ppid[i]].push_back(pid[i]);
            }
        }
        result.push_back(kill);
        vector<int> root;
        root.push_back(kill);
        while (root.size() > 0)
        {
            vector<int> value;
            int key = root.back();
            root.pop_back();

            if (ppid_pid.find(key) != ppid_pid.end())
            {
                value = ppid_pid[key];
                for (int i = 0; i < value.size(); i++)
                {
                    result.push_back(value[i]);
                    root.push_back(value[i]);
                }
            }
        }
        return result;
    }
};

int main(int argc, char * argv[])
{
    vector<int> pid, ppid;

    pid.push_back(1);
    pid.push_back(3);
    pid.push_back(10);
    pid.push_back(5);

    ppid.push_back(3);
    ppid.push_back(0);
    ppid.push_back(5);
    ppid.push_back(3);

    vector<int> result = (new Solution())->killProcess(pid, ppid, 5);

    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    return 0;
}
