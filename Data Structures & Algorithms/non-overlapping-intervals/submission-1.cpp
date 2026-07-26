class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        int maxm=0,res=0;
        
        for(auto &i:intervals){
            if(ans.empty()){
                ans.push_back(i);
                continue;
            }
            if(i[0]<ans[0][1]) {
                ans[0][1]=min(ans[0][1],i[1]);
                res++;
            }
            else ans[0]=i;
        }
        return res;
    }
};
