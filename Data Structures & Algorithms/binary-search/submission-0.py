class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,r=0,len(nums)
        ans =-1
        while l<r:
            mid = (r+l)//2
            t = nums[mid]
            if target<=t:
                r=mid
            elif target>t:
                l=mid+1
    
        if (l<len(nums)) and nums[l]==target:
            return l
        else:
            return -1
