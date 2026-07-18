class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        nums.sort()
        self.arr = nums[max(0,len(nums)-k):]
        self.k = k

    def add(self, val: int) -> int:
        if len(self.arr)< self.k:
            self.arr.append(val)
            self.arr.sort()
        elif self.arr[0] < val:
            self.arr[0] = val
            self.arr.sort()
        return self.arr[0]
        
        
