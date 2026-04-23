# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def sameTree(root, subRoot):
            if not root:
                return not subRoot

            return (subRoot != None 
                    and root.val == subRoot.val
                    and sameTree(root.left, subRoot.left)
                    and sameTree(root.right, subRoot.right)
                )
        
        if sameTree(root, subRoot):
            return True
        
        if not root:
            return False

        if not root.left and not root.right:
            return False

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)