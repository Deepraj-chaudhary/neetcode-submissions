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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(!root) return ans;
        while(q.size()){
            int n = q.size();

            TreeNode* curr = q.front();
            for (int i=0;i<n;i++){
                curr = q.front();
                
                if (curr->left){
                    q.push(curr->left);
                }
                if (curr->right){
                    q.push(curr->right);
                }
                q.pop();
            }
            ans.push_back(curr->val);
        
        }

        return ans;
    }
};
