#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

/**
 * 思路：先对序列排序，找出第一个非负元素，然后先看其下标，若为奇数，肯定不能构成，返回false；在以该下标为界，分为两部分，分别开始找是否存在二倍的元素（负数部分和非负数部分思路一样，但负数反着来）
 * 同时维护一个数组flag用于标识哪些元素已经用过了，用过了就跳过。最后若是能够完全遍历，则返回true。这个复杂度太高，Leetcode超出时间限制，应该改为unorded_map来做。
 */
class Solution
{
public:
    bool compare(int a,int b){
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int> &A)
    {
        if(A.size()==0){
            return true;
        }
        int first, second;
        sort(A.begin(), A.end(),compare);
        int *flag = new int[A.size()]();
        int positive = 0;
        for (; positive < A.size(); positive++)
        {
            if (A[positive] < 0)
            {
                positive++;
            }
            else
            {
                break;
            }
        }
        if (positive % 2 != 0)
            return false;
        
        // cout << positive << endl;

        int left = positive - 1;
        int right = positive;

        while (left >= 0)
        {
            if (flag[left] != 0)
            {
                left--;
                continue;
            }
            int l_left = left - 1;
            int tmp = A[left];

            while (l_left >= 0)
            {
                if(flag[l_left] != 0){
                    l_left--;
                    continue;
                }
                if (A[l_left] == 2 * tmp)
                {
                    flag[l_left] = 1;
                    flag[left] = 1;
                    break;
                }
                l_left--;
            }

            // cout << l_left << endl;
            if(l_left==-1){
                return false;
            }

            left--;
        }


        while (right<A.size())
        {
            if(flag[right] != 0){
                right++;
                continue;
            }


            int r_right = right+1;
            int tmp = A[right];
            while (r_right<A.size())
            {
                if(flag[r_right] != 0){
                    r_right++;
                    continue;
                }

                if(A[r_right]==2*tmp){
                    flag[r_right]=1;
                    flag[right]=1;
                    break;
                }
                r_right++;

            }

            // cout << "r_right: " << r_right << endl;
            if(r_right==A.size()){
                return false;
            }

            right++;
            
        }

        // for (int i = 0; i < A.size();i++)
        // {
        //     cout << flag[i] << endl;
        // }
        
        return true;
    }
};