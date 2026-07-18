class Solution:

    def encode(self, strs: List[str]) -> str:
        ans=""
        for st in strs:
            ans+= str(len(st))+'#'+st
        return ans

    def decode(self, s: str) -> List[str]:
        ans=[]
        i=0

        while i<len(s):
            j=i
            while s[j] != '#':
                j+=1
            l= int(s[i:j])
            j+=1
            st=s[j:j+l]
            ans.append(st)
            i=j+l
        return ans
