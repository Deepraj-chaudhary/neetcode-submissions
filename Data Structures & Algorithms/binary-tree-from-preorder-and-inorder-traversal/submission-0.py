# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        hmap = { v:i for i,v in enumerate(inorder)}
        def bt(prel,prer,inl,inr):
            if inl > inr:
                return None
            root = TreeNode(preorder[prel])
            i = hmap[root.val]
            lsize = i-inl
            root.left = bt(prel+1,prel+lsize,inl,i-1)
            root.right = bt(prel+1+lsize,prer,i+1,inr)
            return root
        
        return bt(0,len(preorder)-1,0,len(inorder)-1)

