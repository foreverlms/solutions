#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    /**
     * 思路：倒序插入，逐个比较nums1与nums2对应位置元素大小，然后判断nums2是否遍历完全，
     * 不是的话能够保证nums1已经完全遍历完了，剩下nums2里面没有遍历的元素肯定是最小的，
     * 直接插入到最前端即可；如果是nums1的元素没有遍历完，就无需做什么。
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0){
            if (nums1[m-1] >= nums2[n-1]){
                nums1[m+n-1] = nums1[m-1];
                m--;
            } else{
                nums1[m+n-1] = nums2[n-1];
                n--;
            }
        }

        while (n > 0){
            nums1[n-1] = nums2[n-1];
            n--;
        }

//        for (auto a : nums1)
//            cout << a << endl;
    }
};