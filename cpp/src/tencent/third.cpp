#include<iostream>

using namespace std;
/**
 * 冰激凌 
 */
int main(void){
    int m,n;
    while (cin>>n>>m)
    {
        int* storage = new int[n];
        int* price = new int[n];
        int* remain = new int[n];
        int remain_max = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>storage[i];
            remain_max = max(storage[i],storage[i-1]) ;
        }

        for (int i = 0; i < n; i++)
        {
            remain[i] = remain_max - storage[i];
        }

        
        
        
    }
    
}