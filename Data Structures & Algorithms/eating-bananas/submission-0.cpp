class Solution {

public:
    int hours(vector<int>& piles, int k){
        int h = 0;
        for(const auto i : piles){
            h+=i%k==0?i/k:(i/k+1);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), maxm = *max_element(piles.begin(),piles.end());
        int l=1,r=maxm;
        while (l<r){
            int mid = l+(r-l)/2;
            if (h>=hours(piles,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
