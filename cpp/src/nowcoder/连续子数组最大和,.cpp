#include <iostream>


using namespace std;

int findMaxSubArray_1(int * source, int len){
    /**
     * 普通方法 o(n)
     */
    if(len<=0 || !source){
        return 0;
    }

    int res = 0;
    int cur = 0;

    for (int i = 0; i < len; i++)
    {
        if(cur <= 0){
            cur = source[i];
        }else{
            cur = cur + source[i];
        }

        res = max(cur,res);
    }
    
    return res;
}

int findMaxSubArray_2(int* source, int len){
    int* dp = new int[len];
    dp[0] = source[0];
    int ans = dp[0];

    for (int i = 1; i < len; i++)
    {
        dp[i] = max(dp[i-1]+source[i],source[i]);
        ans = max(ans,dp[i]);
    }
    return ans;
}