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

    int solve(TreeNode* root, bool* ans ){
        if (root == nullptr) return 0;
        int l = solve(root->left,ans), r = solve(root->right,ans);
        *ans = abs(l-r)<2?*ans:false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve (root,&ans);
        return ans;
    }
};
