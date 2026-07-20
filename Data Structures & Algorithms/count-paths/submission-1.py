class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        v=n+m-2
        u=n-1;
        ans=1;
        j=1
        for i in range(m,m+n-1):
            ans*=i
            ans //= j
            j+=1
        return ans


        
