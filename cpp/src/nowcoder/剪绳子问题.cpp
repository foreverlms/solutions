#include <iostream>
#include <cmath>


using namespace std;

/**
 * 给一根长度为n(n>1)的绳子，请把绳子剪成若干(不妨为m>1)段，每段绳子的长度记为k[i]。k[0]*k[1]*...k[m-1]最大值可以是？
 */

//动态规划
int dynamicSolution(int length)
{
    //f(n)表示将长度为n的绳子剪成若干段所能达到的最大乘积
    //自底向上递归
    if (length < 2)
        return 0;
    if (length == 2)
    {
        return 1;
    }

    if (length == 3)
    {
        return 2; //长度为3的绳子可以剪成1-1-1或者1-2，但是1*2 > 1*1*1
    }

    int *dp = new int[length + 1]; //要包含dp[length]
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int max_res = 0;

    for (int i = 4; i < length; i++)
    {
        max_res = 0;
        //没必要全部遍历，剪成i,length-i和length-i，i两段结果是一样的，倒着剪，正着剪。
        for (int j = 1; j <= i / 2; j++)
        {
            //状态转移方程：f(i) = max(f(i)*f(j-i),max_res)
            max_res = max(dp[j] * dp[i - j], max_res);
        }

        dp[i] = max_res;
    }

    max_res = dp[length];
    delete[] dp;

    return max_res;
}

//贪婪算法

int greedySolution(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if(length == 3)
        return 2;
    
    int segmentsof3 = length/3;//尽可能剪长度为3的绳子

    if(length-segmentsof3*3 == 1){
        segmentsof3-=1;//如果可以分成3*i+1段，那么不应该减去i段长度为3的，应该减去i-1段长度为3，剩下是长度为4的一段，剪成2-2
    }

    int segmentsof2=(length-segmentsof3*3)/2;

    return (int)(pow(3,segmentsof3))*(int)(pow(2,segmentsof2));
}