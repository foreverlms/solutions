package com.bob;

import java.util.Stack;

/**
 * @author :bobliao
 * @description :Leetcode solutions in Java.
 * @version: :v1.0
 * @date :Created in 19-3-4 下午11:06
 */

public class Solution {
    /**
     * Leetcode 64 动态规划
     * @param grid
     * @return
     */
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] sum = new int[m][n];

        for (int i = 0; i<m;++i){
            for (int j = 0; j<n;++j){
                if (i==0 && j ==0){
                    sum[i][j] = grid[0][0];
                }else if (i == 0){
                    sum[i][j] = sum[i][j-1]+grid[i][j];
                }else if (j == 0){
                    sum[i][j] = sum[i-1][j] + grid[i][j];
                }else {
                    sum[i][j] = Math.min(sum[i-1][j],sum[i][j-1]) + grid[i][j];
                }
            }
        }

        return sum[m-1][n-1];
    }

    /**
     * Leetcode 20 栈的用法，每次都把{,(,[压入栈内，碰到},),]就和栈顶的元素比较，是否配对
     * @param s
     * @return
     */
    public boolean isValid(String s) {
        int len = s.length();
        if (len == 0)
            return true;
        if (len % 2 == 1)
            return false;
        Stack<Character> stack = new Stack<>();
        for (int i = 0;i<len;++i){
            char tmp = s.charAt(i);
            if (tmp == '{' || tmp == '(' || tmp == '['){
                stack.push(tmp);
            }
            else if (stack.isEmpty() || (tmp == '}' && stack.pop() != '{') || (tmp == ']' && stack.pop() != '[') || (tmp == ')' && stack.pop() != '('))
                return false;
        }

        return stack.isEmpty();
    }
}
