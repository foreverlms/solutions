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

void all_sort(int *source, int start, int len){
    if(start == len-1){
        show(source,len);
    }
}