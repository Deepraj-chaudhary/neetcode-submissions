class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        solve(coins,amount,dp);
        return dp[amount]>=1e9?-1:dp[amount];
    }
    int solve(vector<int>& coins, int amount, vector<int> &dp){
        if(!amount) return dp[amount]=0;
        if(dp[amount]!=-1) return dp[amount];

        int ans = 1e9;
        for(int coin:coins){
            if(amount-coin>=0)
            ans = min(solve(coins,amount-coin,dp)+1,ans);
        }
        return dp[amount]=ans;
    }
};
