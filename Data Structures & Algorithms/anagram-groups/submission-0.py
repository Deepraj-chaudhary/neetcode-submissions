class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        sort = strs.copy()
        for i in range(0,len(sort)):
            sort[i] = ''.join(sorted(sort[i]))
        for i in strs:
            srt = ''.join(sorted(i))
            if srt not in ans:
                ans[srt]=[]
            ans[srt].append(i)
        return list(ans.values())
    