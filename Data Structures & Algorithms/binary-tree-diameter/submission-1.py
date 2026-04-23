# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        def dfs(root, count):
            if root == None:
                return count

            return max(
                dfs(root.left, count + 1), 
                dfs(root.right, count + 1)
            )
        
        left_height = dfs(root.left, 0)
        right_height = dfs(root.right, 0)

        diameter = left_height + right_height
        
        return max(diameter, max(self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right)))