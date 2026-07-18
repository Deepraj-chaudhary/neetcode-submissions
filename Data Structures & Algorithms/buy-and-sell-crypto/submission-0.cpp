class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int msp = prices[n-1];
        int ans =0;
        for (int i=n-2;i>=0;i--){
            msp = max(msp,prices[i]);
            ans = max(ans,msp-prices[i]);
        }
        return ans;
    }
};
