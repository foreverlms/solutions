#include <iostream>

using namespace std;
//47
//礼物最大价值 o(m*n) 空间 o(m*n)
int maxToatalValue(int **boxes, int rows, int cols)
{
    if (boxes == nullptr || rows <= 0 || cols <= 0)
    {
        return 0;
    }

    int **dp = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dp[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int left = 0; //左边框
            int up = 0;   //上边框

            if (i > 0)
            {
                up = dp[i - 1][j];
            }

            if (j > 0)
            {
                left = dp[i][j - 1];
            }

            dp[i][j] = max(left, up) + boxes[i][j];
        }
    }

    int res = dp[rows - 1][cols - 1];

    //一定要记得释放

    for (int i = 0; i < rows; i++)
    {
        delete[] dp[i];
    }

    delete[] dp;
    dp = nullptr;

    return res;
}

//优化： 只需保存0->j-1,i和i-1,j->cols-1的数据即可 时间 o(m*n) 空间 o(n)

int optimize(int **boxes, int rows, int cols)
{
    if (boxes == nullptr || rows <= 0 || cols <= 0)
    {
        return 0;
    }

    int *dp = new int[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int left = 0;
            int up = 0;

            if (i > 0)
            {
                up = dp[j];
            }

            if (j > 0)
            {
                left = dp[j - 1];
            }

            dp[j] = max(left, up) + boxes[i][j]; //优化了空间复杂度
        }
    }

    int res = dp[cols - 1];
    delete[] dp;
    dp = nullptr;
    return res;
}