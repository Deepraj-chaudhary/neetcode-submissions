class Solution {
public:
    int binarysearch(vector<int> &a,int n,int l,int r){
        while (l<r){
            int mid = (r+l)/2;
            if(n <a[mid]){
                r=mid; 
            }
            else if (n>a[mid]){
                l=mid+1;
            }
            else{
                return mid;
            }
        }
        return r;

    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        for(int i=0; i<n; i++ ){
            int req = target- numbers[i];
            int l=0,r=n-1;
            if(req<numbers[i])r=i-1;
            else l=i+1;

            int ans=binarysearch(numbers,req,l,r);
            if (numbers[ans]==req){
                return {min(ans,i)+1,max(ans,i)+1};
            }
        }
        
    }
};
