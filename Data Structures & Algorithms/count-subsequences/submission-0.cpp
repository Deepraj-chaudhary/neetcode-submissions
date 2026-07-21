class Solution {
public:
    int n,m;
    int numDistinct(string s, string t) {
        n=s.size(),m=t.size();
        if(m>n) return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,dp,s,t);
    }
    int solve(int i,int j,vector<vector<int>> &dp,string &s, string &t){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        ans+=solve(i+1,j,dp,s,t);
        if(s[i]==t[j]) ans+=solve(i+1,j+1,dp,s,t);
        
        return dp[i][j]=ans;
    }
};
