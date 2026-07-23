class Solution {
public:
    int n,m;
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,2));
        return solve(0,0,s,p,dp);
    }
    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(j==m && i==n) return 1;

        if(dp[i][j]!=2) return dp[i][j];
        int ans =0;
        if(p[j]=='*' || (j+1<m && p[j+1]=='*')) {
            ans |= solve(i,j+1,s,p,dp);
        }
        if(i<n){
            if(s[i]==p[j]) ans|= solve(i+1,j+1,s,p,dp);
            else if(p[j]=='.') ans|= solve(i+1,j+1,s,p,dp);
            else if(p[j]=='*' && (s[i]==p[j-1] || p[j-1]=='.')) ans|= (solve(i+1,j,s,p,dp)|solve(i+1,j+1,s,p,dp));
        }
        return dp[i][j]=ans;
    }
};
