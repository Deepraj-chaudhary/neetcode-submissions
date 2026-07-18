class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        premult=[i for i in nums]
        postmult=[i for i in nums]
        for i in range(1,len(premult)):
            premult[i]*=premult[i-1]
        for i in range(len(postmult)-2,-1,-1):
            postmult[i]*=postmult[i+1]
        ans = [postmult[1]]
        for i in range(1,len(premult)-1):
            ans.append(premult[i-1]*postmult[i+1])
        ans.append(premult[len(premult)-2])
        return ans