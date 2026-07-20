class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0),target;

        if(sum%2!=0) return false;
        else target=sum/2;
        vector <bool> dp(target+1,false);
        dp[0]=true;
        for(auto num: nums){
            for(int i=target;i>=num;i--){
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
};
