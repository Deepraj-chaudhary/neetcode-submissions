class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,ans=INT_MIN;
        for(int num : nums){
            curr+=num;
            if(curr<0){
                ans=max(ans,curr);
                curr=0;
                continue;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};
