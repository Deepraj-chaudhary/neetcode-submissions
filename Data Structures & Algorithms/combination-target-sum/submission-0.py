class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        
        def create(i,curr,s):
            if s == target:
                ans.append(curr[:])
                return
            elif s > target or i == len(nums):
                return
            
            curr.append(nums[i])
            s+=nums[i]
            create(i,curr,s)
            s-=nums[i]
            curr.pop()
            create(i+1,curr,s)
            
        create(0,[],0)
        return ans


