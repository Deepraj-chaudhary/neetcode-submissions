class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n=len(heights)
        lmin = [-1]*n
        rmin = [n]*n
        stack = []
        for i,h in enumerate(heights):
            while stack and heights[stack[-1]] >= h:
                stack.pop()
            if stack:
                lmin[i] = stack[-1]
            else:
                lmin[i] = -1
            stack.append(i)
        stack=[]
        for i,h in enumerate(heights):
            while stack and heights[stack[-1]] > h:
                rmin[stack.pop()]=i
            stack.append(i)
        
        maxh = 0
        for i,h in enumerate(heights):
            maxh = max (maxh, (rmin[i]-lmin[i]-1)*h)

        return maxh
