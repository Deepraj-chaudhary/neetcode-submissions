class Solution {
public:
    vector<pair<int,int>> dirn = {{1,0},{0,1}};
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=1;
        return solve(0,0,dp);
    }
    int solve(int i,int j,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        for(auto [a,b]: dirn){
            int r=i+a,c=j+b;
            if(r<dp.size() && r>=0 && c<dp[0].size() && c>=0){
                ans+=solve(r,c,dp);
            }
        }
        return dp[i][j]=ans;
    }
};
