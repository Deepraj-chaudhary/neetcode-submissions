class Solution {
public:
    int numDecodings(string s) {
        int ans =0,n= s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
    int solve(int i,string &s,vector<int>& dp){
        if (i == s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int res = solve(i+1,s,dp);
        if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1] <= '6' ))){
            res += solve(i+2,s,dp);
        }
        return dp[i] = res;
    }
};
