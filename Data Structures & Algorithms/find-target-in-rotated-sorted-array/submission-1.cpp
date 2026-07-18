class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l =0,r=n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if (nums[mid]<nums[r]){
                if(target<=nums[r] && target>nums[mid]) l= mid+1;
                else r = mid;
            }
            else{
                if(target<=nums[mid] && target >= nums[l]) r=mid;
                else l=mid+1;
            }
        }
        if(l<n && nums[l]==target) return l;
        return -1;
    }
};
