// 631. Design Excel Sum Formula
// https://leetcode.com/contest/leetcode-weekly-contest-38/problems/design-excel-sum-formula/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::pair;
using std::map;


class Excel {
public:
    Excel(int H, char W) {
        excel.resize(H + 1);
        for (int i = 0; i < excel.size(); i++)
        {
            excel[i].resize(W - 'A');
        }
    }
    
    void set(int r, char c, int v) {
        excel[r][c - 'A'] = v;
        if (func_cel.find(std::make_pair(r,c)) != func_cel.end())
        {
            func_cel.erase(std::make_pair(r,c));
        }

        recompute_func(-1, '0');
    }
    
    int get(int r, char c) {
        return excel[r][c - 'A'];
    }

    int getRectange(int row1, char col1, int row2, char col2)
    {
        int result = 0;
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1 - 'A'; j <= col2 - 'A'; j++)
            {
                result += excel[i][j];
            }
        }
        return result;
    }

    void recompute_func(int r, char c)
    {
        map<pair<int,char>, vector<string> >::iterator iter = func_cel.begin();
        for (; iter != func_cel.end(); iter++)
        {
            int row = (*iter).first.first; char col = (*iter).first.second;
            if (row == r && col == c)
                continue;
            std::cout << "row = " << row << " col = " << col << std::endl;
            sum(row, col, (*iter).second, false);
        }
    }

    int sum(int r, char c, vector<string> strs)
    {
        return sum(r, c, strs, true);
    }

    int sum(int r, char c, vector<string> strs, bool recompute) {
        int result = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string cell = strs[i];
            if (cell.find(":") != string::npos)
            {
                int pos = cell.find(":");
                int row1 = atoi(cell.substr(1, pos - 1).c_str()), row2 = atoi(cell.substr(pos + 2).c_str());
                char col1 = cell[0], col2 = cell[pos + 1];
                std::cout << cell << " = " << getRectange(row1, col1, row2, col2) << std::endl;
                result += getRectange(row1, col1, row2, col2);
            }
            else
            {
                int row = atoi(cell.substr(1).c_str()); char col = cell[0];
                std::cout << "sum row = " << row << " col = " << col << std::endl;
                result += get(row, col);
            }
        }
        excel[r][c - 'A'] = result;
        func_cel[std::make_pair(r, c)] = strs;
        if (recompute)
            recompute_func(r, c);
        return excel[r][c - 'A'];
    }

private:
    vector<vector<int> > excel;
    map<pair<int, char>, vector<string> > func_cel;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */

 int main(int argc, char * argv[])
{
    Excel *obj = new Excel(26, 'Z');

    obj->set(1, 'A', 1);
    obj->set(1, 'I', 1);

    vector<string> strs1;
    strs1.push_back("A1:D6");
    strs1.push_back("A1:G3");
    strs1.push_back("A1:C12");
    obj->sum(7, 'D', strs1);

    vector<string> strs2;
    strs2.push_back("A1:D7");
    strs2.push_back("D1:F10");
    strs2.push_back("D3:I8");
    strs2.push_back("I1:I9");
    std::cout << obj->sum(10, 'G', strs2);

    /*
    vector<string> strs1;
    strs1.push_back("A2");
    obj->sum(1, 'A', strs1);

    obj->set(2, 'A', 1);
    vector<string> strs2;
    // strs2.push_back("A1");
    // obj->sum(3, 'A', strs2);
    std::cout << obj->get(1, 'A') << " " << obj->get(2, 'A') << std::endl;
    */
    return 0;
}