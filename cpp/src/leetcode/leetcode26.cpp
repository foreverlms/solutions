//
// Created by bob on 19-3-9.
//

#include <vector>
#include <iostream>


class Solution{
public:
    /**
     * 思路：遍历vector，如果前一个数与后一个数不一样，就更新的值并将更新后tmp位置的元素置为后一个数
     * 总体来说就是要i累加，只在前后两个数不一样时才累加tmp
     * @param nums
     * @return
     */
    int removeDuplicates(std::vector<int>& nums){
        if (nums.empty())
            return 0;
        int tmp = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == nums[i+1]){

            } else{
                ++tmp;
                nums[tmp] = nums[i+1];
            }
        }

        return tmp+1;
    }
};


