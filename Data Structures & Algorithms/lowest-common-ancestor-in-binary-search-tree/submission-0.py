# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lca(self, root: TreeNode, p: TreeNode, q: TreeNode):
        if root == None:
            return (False,False,None)
        l = self.lca(root.left,p,q)
        r = self.lca(root.right,p,q)

        pp = l[0] or r[0] or root.val == p.val
        pq = l[1] or r[1] or root.val == q.val
        ans = l[2]
        if not ans:
            ans = r[2]
            if not ans and pp and pq:
                ans = root
                

        return (pp,pq,ans)

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        a = self.lca(root,p,q)[2]
        return a 