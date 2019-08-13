//
// Created by bob on 19-3-10.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val){
                nums[tmp] = nums[i];
                ++tmp;
            }
        }
    }
};