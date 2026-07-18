class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n = len(s)
        if n != len(t):
            return False
        freq={}
        for i in s:
            if i not in freq:
                freq[i]=1
            else:
                freq[i]+=1
        for i in t:
            if i not in freq:
                return False
            else:
                freq[i]-=1
        for i in t:
            if freq[i] != 0:
                return False
        return True
    


