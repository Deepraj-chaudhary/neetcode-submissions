# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -2000
        def dfs(root):
            nonlocal ans
            if root == None:
                return 0
            
            l = max(0,dfs(root.left))
            r = max(0,dfs(root.right))

            ans = max(ans,l+r+root.val)
            return max(l,r) + root.val
        ans = max(dfs(root),ans)
        return ans



