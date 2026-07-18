class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        target = len(nums)-k
        def quickselect(l,r):
            if l==r:
                return l
            mid = (l+r)//2
            candidates = [(nums[l], l), (nums[mid], mid), (nums[r], r)]
            candidates.sort(key=lambda x: x[0])
            p = candidates[1][1]

            nums[l],nums[p] = nums[p],nums[l]
            i,j = l,r
            pivot = nums[l]
            
            while i < j:
                while i < j and nums[j] >= pivot:
                    j -= 1
                while i < j and nums[i] <= pivot:
                    i += 1
                
                if i < j:
                    nums[i], nums[j] = nums[j], nums[i]

            nums[j],nums[l]=nums[l],nums[j]

            if j==target:
                return j
            elif j<target:
                return quickselect(1+j,r)
            else:
                return quickselect(l,j-1)
        return nums[quickselect(0,len(nums)-1)]


