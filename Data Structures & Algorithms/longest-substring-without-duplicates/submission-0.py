class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        l,r=0,0
        has = set()
        ans =0
        while r!=n:
            if s[r] not in has:
                has.add(s[r])
                ans = max(ans, r-l+1)
                r+=1
                continue
            while s[r] in has and l<r:
                has.discard(s[l])
                l+=1
            has.add(s[r])
            ans = max(ans, r-l)
            r+=1
        return ans


