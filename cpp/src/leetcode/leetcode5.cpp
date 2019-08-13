#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
        {
            return s;
        }

        int start = 0;
        int len = s.size();
        int left, right;
        int max_length = 0;

        for (int i = 0; i < len;)
        {
            if ((len - i) < max_length / 2)
            {
                break;
            }

            left = i;
            right = i;

            //如果有连续重复字符,跳过
            while ((right < len - 1) && s[right] == s[right + 1])
            {
                right++;
            }
            //如果有连续重复字符,那么下一次应该从right+1开始遍历;没有则与i=i+1等效
            i = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1])
            {
                right++;
                left--;
            }

            //如果跨度值比max_length还大,那么更新start和max_length的值
            if (max_length < right - left + 1)
            {
                start = left;
                max_length = right - left + 1;
            }
        }
        return s.substr(start, max_length);
    }
};