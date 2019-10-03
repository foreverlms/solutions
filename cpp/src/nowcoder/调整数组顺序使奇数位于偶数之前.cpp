#include <iostream>

using namespace std;

//1 双指针法
void swap(int& a,int& b){
    int tmp = a;
    a = b;
    b = a;
}

void double_pinter(int * source,int len){
    if(len <= 1 || !source){
        return;
    }

    int left = 0;
    int right = len -1;

    while (left < right)
    {
        while (source[left]%2 != 0)
        {
            left++;
        }

        while(source[right] %2 == 0){
            right--;
        }
        //此处需要加判断来保证经过一系列++ --之后仍然满足left < right的条件
        if(left < right){
            swap(source[left],source[right]);
        }
    }
    
}
int main(void){

}