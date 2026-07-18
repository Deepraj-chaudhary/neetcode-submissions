class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        return max(top(n-1,dp,nums),top(n-2,dp,nums));
    }

    int top(int i,vector<int> &dp, vector<int>& nums){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=(max(top(i-2,dp,nums),top(i-3,dp,nums))+nums[i]);
    }
};
