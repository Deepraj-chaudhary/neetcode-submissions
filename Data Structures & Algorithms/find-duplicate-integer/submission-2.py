class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i,p in enumerate(nums):
            pos = abs(p) -1
            if nums[pos] < 0:
                return abs(pos)+1
            nums[pos] = -nums[pos]
            

             
            
            
