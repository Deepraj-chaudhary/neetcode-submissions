class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,n=matrix[0].size(), m=matrix.size();
        int r = m*n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(target<=matrix[mid/n][mid%n]) r=mid;
            else l=mid +1;
        }
        if(l<m*n && matrix[l/n][l%n]==target) return true;
        return false;
    }
};
