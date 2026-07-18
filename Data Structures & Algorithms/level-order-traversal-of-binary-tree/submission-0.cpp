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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if (root==nullptr) return ans ;
        TreeNode* temp = new TreeNode(-1);
        
        queue<TreeNode*> s;
        s.push(root);
        s.push(temp);
        

        while(s.front()!=temp){
            TreeNode* t = s.front();
            vector<int> a1;
            while(t!=temp){
                a1.push_back(t->val);
                if (t->left){
                    s.push(t->left);
                }
                if (t->right){
                    s.push(t->right);
                }
                s.pop();
                t = s.front();
            }
            ans.push_back(a1);
            s.push(temp);
            s.pop();          
        }
        return ans;
    }
};
