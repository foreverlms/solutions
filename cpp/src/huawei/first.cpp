#include <iostream>
#include <algorithm>
using namespace std;

// void swap(int& a,int& b){
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
// /**
//  * 求取二个正整数的最大公约数
//  */
// int getMax(int a,int b){
//     if(a < b){
//         swap(a,b);
//     }

//     int tmp = a % b;
//     while (tmp!=0)
//     {
//         a = b;
//         b = tmp;
//         tmp = a %b;
//     }
    
// }

void judge(int n){
    int y = 0;
    int tmp = 0;
    int min_number = INT32_MAX;
    int limit = 1 + n / 4;
    while (y < limit)
    {
        tmp = n - 4 * y;
        if (tmp % 9 == 0)
        {
            min_number = min(min_number,tmp/9 + y);
        }

        y++;
    }
    
    if(min_number == INT32_MAX){
        cout << -1 << endl;
    }else{
        cout << min_number << endl;
    }
}
int main(void){
    int n;
    cin>>n;
    //9x+4y=n
    judge(n);
    
}