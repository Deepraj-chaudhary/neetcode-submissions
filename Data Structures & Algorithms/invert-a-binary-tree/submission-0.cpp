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
    TreeNode* iinvertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* l = iinvertTree(root->right), *r = iinvertTree(root->left);
        root->left = l;
        root->right = r;

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* l = invertTree(root->right), *r = invertTree(root->left);
        root->left = l;
        root->right = r;

        return root;        
    }
};
