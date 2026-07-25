class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag=false,found=false;
        int start=-1;
        for(auto &v:intervals){
            if((v[1]<newInterval[0] && !flag) || found) ans.push_back(v);
            else{
                if(flag){
                    if(v[1]>=newInterval[1]){
                        if(v[0]>newInterval[1]){
                            ans.push_back({start,newInterval[1]});
                            ans.push_back(v);
                        }
                        else ans.push_back({start,v[1]});

                        found=true;
                        start=-2;
                    }
                }
                else{
                    if(v[0]>newInterval[1]){
                        ans.push_back(newInterval);
                        ans.push_back(v);
                        found=true;
                        start=-2;
                        continue;
                    }
                    start=min(newInterval[0],v[0]);
                    flag=true;
                }
            }
        }
        if(flag && start!=-2) ans.push_back({start,max(newInterval[1],intervals[intervals.size()-1][1])});
        if(start==-1) ans.push_back(newInterval);
        return ans;
    }
};
