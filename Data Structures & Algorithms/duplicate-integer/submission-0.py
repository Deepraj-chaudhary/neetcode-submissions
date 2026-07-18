
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        freq = {}
        for i in nums:
            if i in freq:
                freq[i]+=1;
            else:
                freq[i]=1;
        for i in freq:
            #return i
            if freq[i] > 1:
                return True
        return False