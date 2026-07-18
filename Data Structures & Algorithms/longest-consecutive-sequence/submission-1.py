class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = list(set(nums))
        nums.sort()
        ans = 0
        count = 1
        for i in range(1,len(nums)):
            if nums[i]==(nums[i-1]+1):
                count+=1
            else:
                ans = max(count,ans)
                count =1
        return  min(max(count,ans),len(nums))

