class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        lmax = [0]*n
        rmax = [0]*n
        currmax = nums[0]
        for i in range(n):
            if i%k == 0:
                currmax = nums[i]
            currmax = max(currmax,nums[i])
            lmax[i] = currmax
        
        currmax = nums[n-1]
        for i in range(n-1,-1,-1):
            if i%k == 0:
                currmax = nums[i]
            currmax = max(currmax,nums[i])
            rmax[i] = currmax

        ans = []
        for i in range(k-1,n):
            ans.append(max(rmax[int(i-k+1)],lmax[i]))

        return ans