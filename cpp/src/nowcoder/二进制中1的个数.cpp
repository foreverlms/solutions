#include <iostream>

using namespace std;

int getOneNumberInBinaryMode(int n){
    int tmp = 1;
    int count = 0;
    while (tmp)
    {
        if(tmp & n){
            count++;
        }

        tmp<<=1;
    }
    
    return count;
}
