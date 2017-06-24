// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/#/description

#include <iostream>
#include <stdio.h>
#include <vector>

using std::vector;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const
      {
          return isInt;
      }
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const
      {
          return val;
      }
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const
      {
          return m;
      }
private:
    bool isInt;
    int val;
    vector<NestedInteger> m;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        visit(nestedList, val);
        iter = -1;  
    }

    void visit(const vector<NestedInteger>& nestedList, vector<int>& val)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                val.push_back(nestedList[i].getInteger());
            }
            else
            {
                visit(nestedList[i].getList(), val);
            }
        }
    }

    int next()
    {
        iter++;
        return val[iter];
    }

    bool hasNext()
    {
        return (iter + 1) < val.size();   
    }

private:
    int iter;
    vector<int> val;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char * argv[])
{
    return 0;
}