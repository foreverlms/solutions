#include <iostream>
#include <string>

/**
 * 编码规则：1->A 2->B 3->C ... 26 ->Z 
 * 给定一个数字N，输出有多少种字符编码可以表示N
 * 
 * 例：
 * 111 -> AAA | AK | KA 三种可能性 -> 3
 * 
 * 解法网址： https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
 */
using namespace std;
int main(void){
    string number;
    int ans,n;
    while (cin>>number)
    {
        n=number.length();
        int count[n+1];
        count[0]=1;
        count[1]=1;
        if(number.at(0) == '0'){
            cout << 0;
            continue;
        }

        for (int i = 2; i <= n; i++)
        {
            count[i]=0;
            if(number[i-1] > '0'){
                count[i]=count[i-1];
            }
            if(number[i-2]=='1'|| (number[i-2] == '2' && number[i-1] < '7')){
                count[i]+=count[i-2];
            }
        }     

        cout << count[n];   
    }
    
}