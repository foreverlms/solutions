#include <iostream>

using namespace std;

/**
 * 二进制回文数
 */

// bool judge(int x)
// {
//     int num = 1;
//     int length = 1; //二进制位数
//     int tmp = x >> 1;

//     while (tmp)
//     {
//         num <<= 1;
//         tmp >>= 1;
//         length++;
//     }

//     //取中间位数
//     length = length / 2;
//     while (length--)
//     {
//         if ((num & x == 0) && (x & 1) != 0)
//         {
//             return false;
//         }

//         x &= (~num);
//         x = x >> 1;
//         num = num >> 2;
//     }
//     return true;
// }
// int main(void)
// {
//     int t;
//     cin >> t;
//     int x; //x一定是一个正整数
//     while (cin >> x)
//     {
//         if (judge(x))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
// }

bool isKInbinary1(int x, int k){
    /**
     * 判断二进制情况下第k位是否为1，返回true为1，返回false为0
     */
    return (x & (1 << (k-1))) ? true : false;
}

bool judge(int x){
    int left = 1;
        int num = 1;
        int length = 1; //二进制位数
        int tmp = x >> 1;

        while (tmp)
        {
            num <<= 1;
            tmp >>= 1;
            length++;
        }
    int right = length;
    //左右对称开始判断
    while (left < right){
        if(isKInbinary1(x,left) != isKInbinary1(x,right)){
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main(void)
{
    int t;
    cin >> t;
    int x; //x一定是一个正整数
    while (cin >> x)
    {
        if (judge(x))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}