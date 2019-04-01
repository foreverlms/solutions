//
// Created by bob on 19-4-1.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 先排序，再从小到大选出小于0的第一个元素，在剩下的里面挑两个满足何为其相反数的元素，同时注意去除重复。
     * @param nums
     * @return
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(),nums.end());
        for (int i = 0;i<nums.size();i++){
            //如果开始出现大于0的元素，跳出，不需要再比了，因为三个都比0大的数不可能和为0
            if (nums[i] > 0)
                break;

            //如果连续的几个元素都为同一个值，只取最后一个为准
            if (i >= 1 && nums[i] == nums[i-1])
                continue;

            int two_sum = -nums[i];

            int left = i+1;
            int right = nums.size() - 1;

            //左右同时逼近来找出和为-nums[i]的组合
            //结束循环的条件为left > right。因为当这个成立时，说明左右遍历相遇，
            // 这时候再继续遍历只是重复而已，不会再出现新的和为-nums[i]的组合了
            while (left < right){

                if (nums[left] + nums[right] == two_sum){
                    result.push_back({nums[i],nums[left],nums[right]});

                    //这种情况要同时去除left和right重复的
                    while (left < right && nums[left] == nums[left+1])
                        left++;

                    while (right > left && nums[right] == nums[right-1])
                        right--;

                    //然后left和right一增一减，到下一个不相同的元素
                    left++;
                    right--;

                }else if (nums[left] + nums[right] < two_sum){
                    //这里只需要去除left重复的元素即可
                    while (left < right && nums[left] == nums[left+1])
                        left++;
                    left++;
                }else{
                    //这里只需要去除right重复的元素即可
                    while (right > left && nums[right] == nums[right-1])
                        right--;

                    right--;

                }
            }
        }

        return result;
    }
};