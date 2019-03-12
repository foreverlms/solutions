//
// Created by bob on 19-3-12.
//

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /**
         * 循环遍历
         */
//        int i = 0;
//        for (i; i < nums.size(); ++i) {
//            if (nums[i] == target || nums[i] > target)
//                return i;
//        }
//
//        return nums.size();

        /**
         * 二分法查找
         */

        int mid;
        int left = 0;
        int right = nums.size()-1;

        while (left <= right){
            mid = left+(right-left)/2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }

        return left;
    }
};