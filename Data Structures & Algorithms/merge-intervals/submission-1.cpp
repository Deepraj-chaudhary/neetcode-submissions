class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        unordered_map<int,int> m;
        vector<vector<int>> ans;
        int maxm=0;
        for(auto &v:intervals){
            maxm=max(maxm,v[1]);
            m[v[0]]=max(v[1],m[v[0]]);
        }
        for(int i=0;i<=maxm;i++){
            if(!m.count(i)) continue;
            if(ans.empty()){
                ans.push_back({i,m[i]});
                continue;
            }
            if(i<=ans.back()[1]) ans.back()[1]=max(ans.back()[1],m[i]);
            else ans.push_back({i,m[i]});
        }
        return ans;
    }
    
};
