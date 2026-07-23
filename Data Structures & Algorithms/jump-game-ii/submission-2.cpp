class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> dp(n+1,0);
        int farthest=0,currrange=nums[0],ans=1;

        for(int i=0;i<n-1;i++){
            farthest = max(farthest,i+nums[i]);
            if(i==currrange){
                ans++;
                currrange=farthest;
            }
        }
        return ans;
    }
};
