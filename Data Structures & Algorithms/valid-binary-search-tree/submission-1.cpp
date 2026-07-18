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
    vector<int> solve(TreeNode* root){
        if(root == nullptr) return {1,INT_MAX,INT_MIN};
        bool ans = true;
        int maxm = root->val, minm = root->val;

            vector <int> a =solve(root->left);
            maxm = max(maxm,a[2]);
            minm = min(minm,a[1]);
            ans = ans && a[0] && root->val > a[2];
        
            a =solve(root->right);
            minm = min(minm,a[1]);
            maxm = max(maxm,a[2]);
            ans = ans && a[0] && root->val < a[1];
        
        return {ans, minm, maxm};
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        bool ans = (solve(root)[0] == 1);
        return ans;
    }
};
