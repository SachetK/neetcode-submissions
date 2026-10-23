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
    int count(TreeNode* root, int max) {
        if (!root) {
            return 0;
        }
        
        auto nextMax = std::max(root->val, max);

        auto countBelow = count(root->left, nextMax);
        countBelow += count(root->right, nextMax); 
        countBelow += (nextMax == root->val);

        return countBelow;
    }
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + count(root->left, root->val) + count(root->right, root->val);
    }
};
