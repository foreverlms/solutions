#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 给定输入： 一行字符串，奇数字母单词反转，偶数字母单词正常输出
 * 例： zai lai yi bian -> iaz ial yi bian
 */
int main(void)
{
    string tmp;
    char a;
    while (cin >> tmp)
    {   a = cin.get();
        if (tmp.size() % 2 == 0)
            {
                cout << tmp;
            }else{
                reverse(tmp.begin(),tmp.end());
                cout << tmp ;
            }
        cout << a ;
    }
}