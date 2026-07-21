class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        //vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        int nextbuy=0,nextnobuy=0,nnbuy=0;
        for(int i=n-1;i>=0;i--){
            int currbuy=max(nextbuy,nextnobuy-prices[i]);
            int currnobuy=max(nextnobuy,nnbuy+prices[i]);
            nnbuy=nextbuy;
            nextbuy=currbuy;
            nextnobuy=currnobuy;

        }
        return nextbuy;
    }
};
