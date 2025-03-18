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
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if(!root) return nullptr;

        // Swap Logic
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recurse
        invertTree(root->left);
        invertTree(root->right);

        // Return
        return root;
    }
};