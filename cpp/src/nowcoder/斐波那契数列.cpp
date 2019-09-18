#include <iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        int i = 2;
        int tmp = 0,first=0,second= 1;
        while (i<=n)
        {
            tmp=first+second;
            first=second;
            second = tmp;
            i++;
        }
        
        return tmp;
    }
};