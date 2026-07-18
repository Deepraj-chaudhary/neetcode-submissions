# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def stringify(self, root: Optional[TreeNode]):
        if root == None:
            return "$#"
        return ("$" + str(root.val) + self.stringify(root.left) + self.stringify(root.right))

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        r1 = self.stringify(root)
        sr = self.stringify(subRoot)

        if sr in r1:
            return True
        return False