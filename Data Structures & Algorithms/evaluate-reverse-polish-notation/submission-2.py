class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        def op(c: str):
            if (c=="+"):
                return True 
            if (c=="-"):
                return True
            if (c=="*"):
                return True
            if (c=="/"):
                return True
            return False
            

        n = len(tokens)
        if (n==1):
            return int(tokens[0])
        
        s = []
        for i in range(len(tokens)):
            c = tokens[i]
            if not op(c):
                s.append(int(c))
                continue

            ans = 0
            a1=s[-1]
            s.pop()
            a2=s[-1]

            s.pop()
            if (c=="+"):
                ans = a1+a2
            if (c=="-"):
                ans = a2-a1
            if (c=="*"):
                ans = a2*a1
            if (c=="/"):
                ans = (int)(a2/a1)
            s.append(ans)

        return s[-1]
            


            


        