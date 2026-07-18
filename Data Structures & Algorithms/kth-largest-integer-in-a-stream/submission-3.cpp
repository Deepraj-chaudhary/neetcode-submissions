class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> mheap;
    int k;
public:

    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;
        for(int i = 0;i<nums.size();i++){
            mheap.push(nums[i]);
        }
        while(mheap.size()>k){
            mheap.pop();
        }
    }
    
    int add(int val) {
        mheap.push(val);
        if (mheap.size()>k) mheap.pop();
        return mheap.top();
    }
};
