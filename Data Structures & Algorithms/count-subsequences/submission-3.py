class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n=len(s)
        m=len(t)
        if m>n:
            return 0
        dp=[[-1 for i in range(m+1)] for _ in range(n+1)]
        for j in range(m+1):
            dp[n][j] = 0 
        for i in range(n+1):
            dp[i][m] = 1
        
        for j in range(m-1,-1,-1):
            for i in range(n-1,-1,-1):
                ans=0
                ans+=dp[i+1][j]
                if s[i]==t[j]:
                    ans+=dp[i+1][j+1]
                dp[i][j]=ans

        return dp[0][0]
        

