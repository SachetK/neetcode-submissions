# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        nodes = []
        
        def inOrderTraversal(root):
            if not root:
                return
            
            if not root.left and not root.right:
                nodes.append(root.val)
                return

            inOrderTraversal(root.left)
            nodes.append(root.val)
            inOrderTraversal(root.right)
        
        inOrderTraversal(root)

        for i in range(1, len(nodes)):
            if nodes[i - 1] >= nodes[i]:
                return False
        
        return True
