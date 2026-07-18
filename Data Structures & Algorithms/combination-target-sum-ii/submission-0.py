class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        nums.sort()
        def create(i,curr,s):
            if s == target:
                ans.append(curr[:])
                return
            
            
            for j in range(i, len(nums)):

                if s + nums[i] > target:
                    return
                if (j>i and nums[j]==nums[j-1]):
                    continue
                
                curr.append(nums[j])
                s+=nums[j]
                create(j+1,curr,s)
                s-=nums[j]
                curr.pop()
            return
            
        create(0,[],0)
        return ans


