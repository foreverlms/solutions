class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # dict_ = dict(zip(nums,[i for i in range(len(nums))]));
        # for i in range(len(nums)):
        # 	for j in range(i,len(nums)):
        # 		key = target - nums[i];
        # 		if dict_.has_key(key) and dict_[key] != i :
        # 			return [i,dict_[key]]
        # return None

        for index,value in enumerate(nums):
        	another = target - value;
        	if another in nums and nums.index(another) != index :
        		return index,nums.index(another)

        return None