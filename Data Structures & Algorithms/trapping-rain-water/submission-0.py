class Solution:
    def trap(self, height: List[int]) -> int:
        p = [i for i in height]
        s = [i for i in height]
        maxm = p[0]
        n= len(height)
        for i in range (1,n):
            p[i]=max(p[i],maxm)
            maxm=p[i]
        maxm = s[n-1]
        for i in range(n-2,-1,-1):
            s[i]=max(s[i],maxm)
            maxm = s[i]
        ans =0
        for i in range (0,n):
            ans += (min(s[i],p[i])-height[i])
        return ans

