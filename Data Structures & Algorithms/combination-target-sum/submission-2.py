class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        nums.sort()
        def create(i,curr,s):
            if s == target:
                ans.append(curr[:])
                return
            
            
            for j in range(i, len(nums)):
                if s + nums[i] > target:
                    return
                
                curr.append(nums[j])
                s+=nums[j]
                create(j,curr,s)
                s-=nums[j]
                curr.pop()
            
        create(0,[],0)
        return ans


