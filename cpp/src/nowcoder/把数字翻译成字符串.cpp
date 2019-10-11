#include <iostream>
#include <string>
using namespace std;

//46

int count(const string &num_str)
{
    int len = num_str.length();
    int *dp = new int[len];

    int count = 0;

    for (int i = len - 1; i >= 0; --i)
    {
        //从后向前
        count = 0; //每次都要将count复位至0`
        if (i < len - 1)
        {
            count = dp[i + 1];
        }
        else
        {
            count = 1; //初始时count就为1
        }

        if (i < len - 1)
        {
            int num_1 = num_str[i] - '0';
            int num_2 = num_str[i + 1] - '0';

            int tmp = num_1 * 10 + num_2;
            if (tmp >= 10 && tmp < 25)
            {
                if (i < len - 2)
                {
                    count += dp[i + 2];
                }
                else
                {
                    count += 1;
                }
            }
        }

        dp[i] = count;
    }

    int res = dp[0];
    delete[] dp;

    return res;
}
int numberOfTranslation(int num)
{
    if (num < 0)
    {
        return 0;
    }

    string num_str = to_string(num);
}