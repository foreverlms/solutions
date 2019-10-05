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

void swap(int& a,int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void all_sort(int *source, int start, int len){
    if(start == len-1){
        show(source,len);
    }

    for (int i = start; i < len; i++)
    {
        swap(source[start],source[i]);
        all_sort(source,start+1,len);
        swap(source[start],source[i]);
    }
    
}