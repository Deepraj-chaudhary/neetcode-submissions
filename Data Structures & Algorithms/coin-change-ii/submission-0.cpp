class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(auto coin : coins){
            for(int i=0;i<=amount;i++){
                if(i - coin>=0) dp[i]+=dp[i-coin];
            }
        }
        return dp[amount];
    }
};
