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
    int solve(TreeNode* root, int k, int* count){
        if (root == nullptr) return INT_MAX;
        int l = solve(root->left,k,count);
        (*count)++;
        if (*count == k){
            return root->val;
        }
        int r = solve(root->right,k,count);
        
        return min(l,r);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return solve(root,k,&count);
    }
};
