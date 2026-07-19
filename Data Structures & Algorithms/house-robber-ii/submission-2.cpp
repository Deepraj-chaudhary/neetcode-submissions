class Solution {

public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp1(n,-1),dp2(n,-1);
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        if (n == 3) return max({nums[0], nums[1], nums[2]});
        return max(max(top(n-1,dp1,nums,n-1),top(n-2,dp1,nums,n-1)),max(top(n-2,dp2,nums,n-2),top(n-3,dp2,nums,n-2)));
    }

    int top(int i,vector<int> &dp, vector<int>& nums,int t){
        if(i<0 || (i<1 && t==n-1)) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=(max(top(i-2,dp,nums,t),top(i-3,dp,nums,t))+nums[i]);
    }

};