//
// Created by bob on 19-3-9.
//

#ifndef LEETCODE48_H
#define LEETCODE48_H

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        int size = matrix.size();

        //先对矩阵做垂直翻转，注意行下标一半就可以了
        for (int i = 0; i < size / 2; ++i) {
            for (int j = 0; j < size; ++j) {
                swap(matrix[size-i-1][j],matrix[i][j]);
            }
        }
        //矩阵沿主对角线对称翻转，注意j的起始值只需要是上三角就可以了
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    }
};

#endif
