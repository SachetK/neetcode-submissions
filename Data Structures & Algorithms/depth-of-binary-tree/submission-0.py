# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def maxDepthHelper(root, count):
            if root == None:
                return count

            return max(maxDepthHelper(root.left, count + 1), maxDepthHelper(root.right, count + 1))

        return maxDepthHelper(root, 0)