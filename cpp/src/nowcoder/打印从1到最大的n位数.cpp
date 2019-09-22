#include <iostream>
#include <string.h>

using namespace std;

bool increment(char *num)
{
    int i = strlen(num)-1;
    for (; i >= 0; i--)
    {
        char tmp = num[i] + 1;

        if (tmp <= '9' && tmp >= '0')
        {
            //如果没进位，直接赋值，并跳出
            num[i] = tmp;
            break;
        }
        else
        {
            //进位，将当前位置0，继续考虑下一位
            num[i] = '0';
        }
    }

    if (i == -1)
    {
        //如果一直进位到-1位，说明溢出了，也就到了最大值
        return true;

    }
    else
    {
        return false;
    }
}
void printToMax(int n)
{
    char *a = new char[n + 1];
    memset(a, '0', n);
    a[n] = '\0';
    
    while (!increment(a))
    {   
        int i = 0;
        for (; i < strlen(a); i++)
        {
            if(a[i] != '0'){
                break;
            }
        }
        
        for (int j = i; j < strlen(a); j++)
        {
            cout << a[j];
        }

        cout << endl;
        
    }
    
}
