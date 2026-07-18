class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
            h = [0]*26

            for v in tasks:
                h[ord(v)-ord("A")]+=1

            unique = 0
            maxm = 0
            for i,v in enumerate(h):
                if v:
                    if v == h[maxm]:
                        unique+=1
                    if v>h[maxm]:
                        maxm = i
                        unique = 1
            
            ans = (n+1)*(h[maxm]-1)+unique
            return max(ans,len(tasks)) 

