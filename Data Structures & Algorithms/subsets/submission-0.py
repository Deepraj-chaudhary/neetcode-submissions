class Solution:

    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        
        def create(i,curr):
            if i == len(nums):
                ans.append(curr[:])
                return
            create(i+1,curr)
            curr.append(nums[i])
            create(i+1,curr)
            curr.pop()
        create(0,[])
        return ans


