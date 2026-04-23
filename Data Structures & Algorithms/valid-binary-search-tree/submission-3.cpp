/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX);
    }

    bool valid(TreeNode* root, int left, int right) {
        if (root == nullptr) {
            return true;
        }

        if (root->val >= right || root->val <= left) {
            return false;
        }

        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }
};
