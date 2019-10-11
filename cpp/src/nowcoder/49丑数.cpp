#include <iostream>

using namespace std;

//49

int getUglyNumber(int index){
    if(index <=0){
        return 0;
    }

    int* ugly_numbers = new int[index];
    ugly_numbers[0]=1;

    int next_ugly_index = 1;

    int* p1 = ugly_numbers;
    int* p2 = ugly_numbers;
    int* p3=ugly_numbers;

    while (next_ugly_index < index)
    {
        int minest = min(*p1*2,*p2*3,*p3*5);
        ugly_numbers[next_ugly_index] = minest;

        while (*p1*2 <= ugly_numbers[next_ugly_index])
        {
            ++p1;
        }

         while (*p2*3 <= ugly_numbers[next_ugly_index])
        {
            ++p2;
        }
        
        while (*p3*5 <= ugly_numbers[next_ugly_index])
        {
            ++p3;
        }
        
        ++next_ugly_index;
    }

    int num = ugly_numbers[next_ugly_index-1];
    delete[] ugly_numbers;
    return num;
    
}