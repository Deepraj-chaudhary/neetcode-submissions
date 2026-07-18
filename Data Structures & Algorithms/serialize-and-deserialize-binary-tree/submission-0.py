# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        q = []
        
        def dfs(root):
            if root == None:
                q.append("N")
                return
            
            q.append(str(root.val))
            dfs(root.left)
            dfs(root.right)
        dfs(root)

        return ",".join(q)     
            
            

    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        q = data.split(",")
        self.i=0

        def dfs():
            if q[self.i] == "N":
                self.i+=1
                return None
            
            node = TreeNode(int(q[self.i]))
            self.i+=1
            node.left = dfs()
            node.right = dfs()

            return node
        
        return dfs()
             

