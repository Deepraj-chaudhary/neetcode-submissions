class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        f = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in f:
                return [f[complement][0], i]
            f[num] = [i]