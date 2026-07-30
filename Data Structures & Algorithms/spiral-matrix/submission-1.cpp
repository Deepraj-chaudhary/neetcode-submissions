class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> ans;

        for(int l=0; l<(min(m,n)+1)/2 ;l++){
            for(int j=l;j<n-l;j++) ans.push_back(matrix[l][j]); 
            for(int i=l+1;i<m-l;i++) ans.push_back(matrix[i][n-1-l]);   
            for(int j=n-2-l;j>=l && m-1-l!=l ;j--) ans.push_back(matrix[m-1-l][j]);  
            for(int i=m-2-l;i>l && n-1-l!=l ;i--) ans.push_back(matrix[i][l]);         
        }

        return ans;  
    }
};
