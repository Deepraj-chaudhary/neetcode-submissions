class Solution:
        
    def minWindow(self, s: str, t: str) -> str:
               
        n = len(s)
        m = len(t)
        if n < m:
            return ""
        f = {}
        for i in t:
            f[i]= -1 + f.get(i,0)
        m=len(f)
        l,r=0,0
        al,ar,alen=0,0,float("infinity")
        have = 0
        while r < n:
            c= s[r]
            if c in f:
                f[c]+=1
            if c in f and f[c]==0:
                have+=1
            while have == m:
                c=s[l]
                if (r-l) < alen :
                    ar,al,alen =r,l,r-l+1
                if c in f:
                    f[c]-=1
                if c in f and f[c]<0:
                    have-=1
                l+=1  
            r+=1

        if alen != float("infinity"):
            return s[al:ar+1]
        return ""
            




            
            

            


