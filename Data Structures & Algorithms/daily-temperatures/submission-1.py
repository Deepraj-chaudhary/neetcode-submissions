class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        s = [(temperatures[-1],n-1)]
        results = [0]*n
        for i in range(n-2,-1,-1):
            t = temperatures[i]
            top = s[-1][0]
            while(len(s) and s[-1][0]<=t):
                s.pop()
            if not len(s):
                results[i]=0
            else:
                results[i]=s[-1][1]-i
            s.append((t,i))
        return results

            
