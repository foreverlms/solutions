//
// Created by bob on 19-3-3.
//

#include "../include/header.h"
#include <math.h>

int Solution::minPathSum(vector<vector<int>>& grid) {
    //定义一个二维数组来存放相对应的累加和
    int sum[grid.size()][grid[0].size()];
    unsigned long m = grid.size();
    unsigned long n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            if (i == 0 && j == 0) {
                //如果遍历到[0,0]也就是矩阵左上角元素，那么最小就必定包含这个元素
                sum[i][j] = grid[0][0];
            } else if (i == 0) {
                //如果正好遍历到行下标为0，那么这一次的最小值肯定是上一步第一行左边那次所记录的最小和加上
                //正好遍历到的元素值
                sum[i][j] = sum[i][j - 1] + grid[i][j];
            } else if (j == 0) {
                //同上，只不过这次变成列下标为0的极端情况
                sum[i][j] = sum[i - 1][j] + grid[i][j];
            } else {
                //不属于以上情况，那么就是之前的向左或向右那一步累加和最小值与正好遍历到的元素值相加
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }
    }


    return sum[m-1][n-1];
}

