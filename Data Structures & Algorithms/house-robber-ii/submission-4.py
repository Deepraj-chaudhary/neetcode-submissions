class Solution:
    def rob(self, nums: List[int]) -> int:
        n= len(nums)
        if n ==1:
            return nums[0]
        if n==2:
            return max(nums[n-1],nums[n-2])
        def solve(start):
            dp = [i for i in nums]
            for i,v in enumerate(nums):
                if i<start:
                    continue
                if i+2-start != n-1 and i+2<n:
                    dp[i+2] = max(dp[i+2],dp[i]+nums[i+2])
                if i+3-start != n-1 and i+3<n:
                    dp[i+3] = max(dp[i+3],dp[i]+nums[i+3])
            return max(dp[n-1],dp[n-2],dp[n-3])

        return max(solve(0),solve(1))