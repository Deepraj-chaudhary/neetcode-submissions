class Solution {
public:
    int n;
    int maxProduct(vector<int>& nums) {
        n= nums.size();
        vector<pair<int,int>> dp(n,{INT_MIN,INT_MAX});
        dp[0]=solve(dp,nums,0);
        int ans = dp[0].first;
        for (int i=0;i<n;i++){
            ans = max(ans,dp[i].first);
        }
        return ans;
    }
    pair<int,int> solve(vector<pair<int,int>> &dp,vector<int>& nums,int i ){
        if(dp[i].first!=INT_MIN) return dp[i];

        int cmax = nums[i], cmin = nums[i];
        if (i!=n-1) {
            auto [maxm,minm] = solve(dp,nums,i+1);
            cmin = min(min(cmin,cmin*maxm),cmin*minm);
            cmax = max(max(cmax,cmax*maxm),cmax*minm);
        }

        return dp[i]={cmax,cmin};
    }
};
