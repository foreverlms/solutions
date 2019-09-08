#include <iostream>

using namespace std;

int NumberAppearMoreThanHalf(int array[])
{
    //找中位数
    int target = array[0];
    int count = 1;

    //不知道array的数组长度啊，不知道是不是出题人漏了？我假定为length=5吧，以长度为5的数组验证
    int length = 5;

    for (int i = 0; i < length; i++)
    {
        if (array[i] != target)
        {
            count--;
            if (count == 0)
            {
                target = array[i];
                count = 1;
            }
        }
        else
        {
            count++;
        }
    }

    return target;
}
int main(void)
{
    int array[5] = {1, 2, 2, 2, 3};

    cout << NumberAppearMoreThanHalf(array) << endl;
}

// int maxSubArray(int* A, int n){

//     if(n==0) return NULL;

//     int ans = INT32_MIN;
//     int sum = -1;
//     //动态规划
//     for (int i = 0; i < n; i++)
//     {
//         //状态转移sum = max(A[i], sum+A[i])
//         sum = max(A[i],sum+A[i]);
//         ans=max(sum,ans);
//     }

//     return ans;

// }