class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //r=min(n,t/2);
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if(nums1.size() > nums2.size()){
            swap(A,B);
        }
        int n=A.size(),m=B.size();
        int t=n+m;
        int l=0,r=n,req=(t+1)/2;
        while(l<=r){
            int i = (r+l)/2;
            int j = req-i;
            int l1 = i>0 ? A[i-1] : INT_MIN;
            int r1 = i<n ? A[i] : INT_MAX;
            int l2 = j>0 ? B[j-1] : INT_MIN;
            int r2 = j<m ? B[j] : INT_MAX;
            
            if (l1 <= r2 && l2<=r1){
                if(t % 2 != 0){
                    return max(l1,l2); 
                } 
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }    
        return -1;
    }
};
