class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        def create(i,curr):
            ans.append(curr[:])
            if i == len(nums): 
                return
                        
            for j in range(i, len(nums)):

                if (j>i and nums[j]==nums[j-1]):
                    continue
                
                curr.append(nums[j])
                create(j+1,curr)
                curr.pop()
            return
            
        create(0,[])
        return ans


