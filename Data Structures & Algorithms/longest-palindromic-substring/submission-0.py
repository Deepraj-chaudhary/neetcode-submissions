class Solution:
    def longestPalindrome(self, s: str) -> str:
        al,ar=0,0

        for i in range(len(s)):
            l,r=i,i
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if (ar-al<r-l):
                    ar,al=r,l
                l-=1
                r+=1
            if i+1<len(s):
                l,r=i,i+1
                while(l>=0 and r<len(s) and s[l]==s[r]):
                    if (ar-al<r-l):
                        ar,al=r,l
                    l-=1
                    r+=1

        return s[al:ar+1]
            
