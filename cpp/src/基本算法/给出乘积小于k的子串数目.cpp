#include <iostream>
#include <vector>

//给定一个正整数组，给出所有元素乘积小于K的子串数目。

//https://blog.csdn.net/qq_41855420/article/details/89597792
//双指针法，保证窗口里的子数组乘积小于k即可
using namespace std;

int getCountOfMultiLessThanKSubarray(int *source, int len,int k)
{
    int left = 0,tmp = 1,ans=0;
    for (int right = 0; right < len; right++)
    {
        tmp*=source[right];
        while (tmp>=k)
        {
            tmp/=source[left];
            left++;
        }

        ans+=right-left+1;
    }
    
    return ans;
}
