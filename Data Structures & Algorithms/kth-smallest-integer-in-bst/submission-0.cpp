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
    void dfs(TreeNode* root, pair<int, int>& vals) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, vals);
        if (vals.first == 0) {
            return;
        }

        // upon finishing, we have reached the leftmost node.
        // This is the smallest
        vals.first--;
        if (vals.first == 0) {
            vals.second = root->val;
            return;
        }

        dfs(root->right, vals);
    }

    int kthSmallest(TreeNode* root, int k) {
        auto vals = make_pair(k, 0);
        dfs(root, vals);
        return vals.second;
    }
};
