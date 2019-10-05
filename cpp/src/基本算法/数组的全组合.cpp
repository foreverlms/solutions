#include <iostream>

using namespace std;

void show(int *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << s[i] << " " << endl;
    }
    cout << endl;
}

void set(int* source,int len){
    //组合有2^n次方种
    for (int i = 0; i < (1<<len); i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(i&(1<<j)){//有没有第j个元素呢？
                cout << source[j] << " ";
            }
        }

        cout << endl;
        
    }
    
}