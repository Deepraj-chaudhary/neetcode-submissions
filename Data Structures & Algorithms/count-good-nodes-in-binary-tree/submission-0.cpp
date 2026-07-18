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
    void solve(TreeNode* root, int maxm, int *ans){
        if (root == nullptr) return;
        if (maxm <= root->val){
            (*ans)++;
        }
        maxm = max(maxm,root->val);
        solve(root->left,maxm,ans);
        solve(root->right,maxm,ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        solve(root,root->val,&ans);
        return ans;
    }
};
