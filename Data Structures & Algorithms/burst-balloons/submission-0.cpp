class Solution {
public:
    int n;
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        return solve(newNums,1,n,dp);
    }
    int solve(vector<int> &nums,int l,int r,vector<vector<int>> &dp){
        if(r<l) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        dp[l][r] = 0;
        for(int i=l;i<=r;i++){
            dp[l][r]=max(dp[l][r],solve(nums,l,i-1,dp)+solve(nums,i+1,r,dp)+nums[l-1]*nums[i]*nums[r+1]);
        }
        return dp[l][r];
    }
};
