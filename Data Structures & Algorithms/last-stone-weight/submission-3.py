class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        b = [0]*101
        for s in stones:
            b[s]+=1
        curr = -1
        i = 100
        while(i>-1):
            if not b[i]:
                i-=1
                continue
            if curr !=-1:
                b[i]-=1
                if curr-i>=i:
                    curr-=i
                    continue
                else:
                    b[curr-i]+=1
                    curr = -1
            v = b[i]
            if v%2 == 0:
                b[i]=0
            else:
                curr = i
            i-=1

            
        return max(curr,0)

