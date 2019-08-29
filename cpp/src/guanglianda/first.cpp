#include <iostream>
#include <string>

/**
 * 输入一个10位正整数从右端开始依次打印5-8位，然后输出这四位的和。
 * inout: 1234567890
 * output: 6543
 *         18
 */

using namespace std;
int main(void)
{
    int n;
    int temp;
    while (cin >> n)
    {
        int i = 0;
        int result = 0;
        while (n / 10)
        {
            temp = n % 10;
            n /= 10;
            i++;
            if (i >= 5 && i <= 8)
            {
                cout << temp;
                result += temp;
                continue;
            }
            if (i > 8)
            {
                cout << endl
                     << result << endl;
                break;
            }
        }
    }
}