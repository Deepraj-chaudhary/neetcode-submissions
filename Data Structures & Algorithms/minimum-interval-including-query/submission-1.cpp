class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0]; 
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),comp);

        vector<pair<int,int>> sortedq;
        for(int i=0;i<queries.size();i++) sortedq.push_back({queries[i],i});
        sort(sortedq.begin(),sortedq.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        vector<int> ans(queries.size());
        int i=0;

        for(auto &[q,ind] :sortedq){
            while(i<intervals.size() && intervals[i][0]<=q){
                heap.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                i++;
            }
            while(!heap.empty() && heap.top().second<q) heap.pop();
            ans[ind]=heap.empty()?-1:heap.top().first;
        }
        return ans;
    }
};
