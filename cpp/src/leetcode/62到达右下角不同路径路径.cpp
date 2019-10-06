#include <iostream>
#include <vector>

using namespace std;

/**
 * 动态规划 dp[i][j] = dp[i-1][j]+dp[i][j-1]
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        // int **matrix = new int*[m];
        // for (int i = 0; i < m; i++)
        // {
        //     matrix[i] = new int[n];
        // }
        if(m==0 || n==0){
            return 0;
        }
        
        if(m==1 || n==1){
            return 1;
        }
        vector<vector<int>> matrix(m,vector<int>(n,0));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==0 || j==0){
                    matrix[i][j] =1;
                }else if(i>0 && j > 0){
                    matrix[i][j] = matrix[i][j-1]+matrix[i-1][j];
                }
            }
            
        }
        
        return matrix[m-1][n-1];
    }
};