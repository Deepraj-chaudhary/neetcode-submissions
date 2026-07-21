class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        //vector<unordered_map<int,int>> dp(n+1);
        unordered_map<int,int> prev;
        prev[0]=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int> curr;
            for(auto &p:prev){
                curr[p.first+nums[i]]+=p.second;
                curr[p.first-nums[i]]+=p.second;
            }
            prev=curr;
        }
        return prev[target];
    }
};
