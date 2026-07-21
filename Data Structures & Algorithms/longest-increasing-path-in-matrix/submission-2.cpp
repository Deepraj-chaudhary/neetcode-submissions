class Solution {
public:
    vector<pair<int,int>> dirn = {{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(i,j,matrix,dp));
            }
        }
        return ans;
    }
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if (dp[i][j]) return dp[i][j];
        int ans=1;
        for(auto [a,b]:dirn){
            int r=a+i,c=b+j;
            if(r>=0 && r<n && c<m && c>=0 && matrix[r][c]>matrix[i][j])
                ans=max(ans,solve(r,c,matrix,dp)+1);
        }
        return dp[i][j]=ans;
    }
};
