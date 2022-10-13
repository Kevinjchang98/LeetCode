# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root: return
        
        q = []
        
        self.pre(root, q)
        
        for index in range(len(q) - 1):
            q[index].left = None
            q[index].right = q[index + 1]
        
    def pre(self, root, q):
        if not root: return
        
        q.append(root)
        
        self.pre(root.left, q)
        self.pre(root.right, q)