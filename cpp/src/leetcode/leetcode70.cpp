//
// Created by bob on 19-3-29.
//

#include <iostream>
#include <vector>

class Solution {
public :
    /**
     * 这个好似斐波那契数列f(n) = f(n-1) + f(n-2)
     * @param n
     * @return
     */
    int climbStairs(int n) {
        if (n == 1)
            return 1;

        int before_one = 1,before_two = 1, total = 0;

        for (int i = 2; i <= n; ++i) {
            total = before_one + before_two;
            before_two = before_one;
            before_one = total;
        }

        return total;
    }
};