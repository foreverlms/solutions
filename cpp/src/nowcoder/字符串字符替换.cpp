#include <iostream>
#include <vector>

using namespace std;

// 从后面到前面，避免多次移动同一内存块
class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        if (str == nullptr || length <= 0)
        {
            return;
        }

        int counter = 0;
        int real_length = 0;
        char *tmp = str;
        while (*tmp != '\0')
        {
            real_length++;
            if (*tmp == ' ')
            {
                counter++;
            }
            tmp++;
        }

        if (str + real_length + counter * 2 > str + length)
        {
            return;
        }
        char *new_str = str + real_length + counter * 2 - 1;
        char *old_str = str + real_length - 1;
        *(new_str + 1) = '\0';

        while (old_str - str >= 0 && new_str - old_str > 0)
        {
            if (*old_str == ' ')
            {
                *new_str = '0';
                new_str--;
                *new_str = '2';
                new_str--;
                *new_str = '%';
                new_str--;
            }
            else
            {
                *new_str = *old_str;
                new_str--;
            }

            old_str--;
        }
    }
};