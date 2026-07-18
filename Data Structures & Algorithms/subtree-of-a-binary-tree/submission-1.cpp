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
    string stringify(TreeNode* root) {
        if (root == nullptr) {
            return "$#";
        }
        return "$" + std::to_string(root->val) + 
               stringify(root->left) + 
               stringify(root->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string r1 = stringify(root);
        string sr = stringify(subRoot);

        if (r1.find(sr) != string::npos) {
            return true;
        }
        return false;
    }
};