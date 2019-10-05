#include <iostream>
#include <algorithm>

using namespace std;
//44

int getTheNthNum(int n){
    int k = 1;
    int cons = 10;
    while (k*cons < n)
    {
        n = n - k*cons;
        k++;
        cons = 9*pow(10,k-1);
    }
    int mod = n % k;
    int div = n/k;

    int start = 0;
    
    if(k>1){
        start =  pow(10,k-1);
    }

    int end = start+div;


    int ans = 0;
    for (int i = 0; i <= k-1-mod; i++)
    {
        ans = end%10;
        end/=10;
    }
    
    return ans;
}