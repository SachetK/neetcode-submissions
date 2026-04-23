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


/**
Solution Approach: Lets do this in a BFS style. 

Start off by adding the root in its own vector. OH NO NEVER MIND!
Create a queue. Add the root to the queue. Then, check size of queue. 
This is how many elements need to be added. Add the first X elements 
to a vector. Push this vector onto the solution.
**/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> sol;

        if (root == nullptr) {
            return sol;
        }

        std::queue<TreeNode*> toVisit;
        toVisit.push(root);
        
        while (!toVisit.empty()) {
            std::vector<int> nodes;
            auto n = toVisit.size();
            for (auto i = 0; i < n; i++) {
                auto node = toVisit.front();
                toVisit.pop();

                if (node->left != nullptr) {
                    toVisit.push(node->left);
                }

                if (node->right != nullptr) {
                    toVisit.push(node->right);
                }

                nodes.push_back(node->val);
            }
            sol.push_back(nodes);
        }

        return sol;
    }
};
