#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.size() <= 0 || numRows == 0)
        {
            return "";
        }

        if (numRows == 1)
        {
            return s;
        }

        int segment_num = 2 * numRows - 2;
        string res;
        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = i; j < s.size(); j += segment_num)
            {
                res.insert(res.end(), s[j]);
                if (i != 0 && i != numRows - 1)
                {
                    int intermediate = j + segment_num - 2 * i;
                    if (intermediate < s.size())
                    {
                        res.insert(res.end(), s[intermediate]);
                    }
                }
            }
        }

        return res;
    }
};