// leetcode 609 https://leetcode.com/problems/find-duplicate-file-in-system/#/description
// 609. Find Duplicate File in System

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        map<string, int> fileContent2DirIndex;
        vector<vector<string> > dirFile;
        for (int i = 0; i < paths.size(); i++)
        {
            // find dir name
            int dir_pos_end = paths[i].find(" ");
            string dir = paths[i].substr(0, dir_pos_end);

            // find file and content
            int file_pos_start;
            int file_pos_end = dir_pos_end;
            do
            {
                file_pos_start = file_pos_end + 1;
                file_pos_end = paths[i].find(" ", file_pos_start);

                string fileAndContent;
                
                if (file_pos_end < 0)
                {
                    fileAndContent = paths[i].substr(file_pos_start);
                }
                else
                {
                    fileAndContent = paths[i].substr(file_pos_start, file_pos_end - file_pos_start);
                }

                std::cout << fileAndContent<< std::endl;

                string file, content;
                int pos_content_start = fileAndContent.find("("), pos_content_end = fileAndContent.find(")");
                content = fileAndContent.substr(pos_content_start + 1, pos_content_end - pos_content_start - 1);
                file = fileAndContent.substr(0, pos_content_start);

                std::cout << content<< " " << file << std::endl;

                if (fileContent2DirIndex.find(content) == fileContent2DirIndex.end())
                {
                    vector<string> newItem;
                    newItem.push_back(dir + "/" + file);
                    dirFile.push_back(newItem);
                    fileContent2DirIndex[content] = dirFile.size() - 1;
                }
                else
                {
                    int index = fileContent2DirIndex[content];
                    dirFile[index].push_back(dir + "/" + file);
                }
            } while (file_pos_end >= 0);
        }

        std::cout << "dirFile.size() = "  << dirFile.size() << std::endl;
        for (int i = 0; i < dirFile.size(); )
        {
            if (dirFile[i].size() < 2)
            {
                std::cout << "erase i " << i << std::endl;
                dirFile.erase(dirFile.begin() + i);
                continue;
            }
            i++;
        }

        return  dirFile;
    }
};


int main(int argc, char * argv[])
{
    vector<string> paths;
    // paths.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
    // paths.push_back("root/c 3.txt(abcd)");
    // paths.push_back("root/c/d 4.txt(efgh)");
    // paths.push_back("root 4.txt(efgh)");

    paths.push_back("root/a 1.txt(abcd) 2.txt(efsfgh)");
    paths.push_back("root/c 3.txt(abdfcd)");
    paths.push_back("root/c/d 4.txt(efggdfh)");

    vector<vector<string> > result;
    result = (new Solution())->findDuplicate(paths);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
