class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cur=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]+i>=cur){
                cur=i;
            }
        }
        return cur==0;
    }
};
