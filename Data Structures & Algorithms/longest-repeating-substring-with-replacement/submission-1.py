class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        ans = 0
        l=0
        maxm = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r],0)
            maxm = max(maxm,count[s[r]])
            while (r-l+1) - maxm >k:
                count[s[l]] -= 1
                l += 1
                for i in s:
                    maxm = max(maxm,count.get(i,0))
            ans = max(ans,r-l+1)
        return ans
    