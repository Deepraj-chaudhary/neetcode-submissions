class Solution {
public:
    void dfs(unordered_map <string,deque<string>> &adj,vector<string> &ans,const string &start){
        while(!adj[start].empty()){
            string dst = adj[start].back();
            adj[start].pop_back();
            dfs(adj,ans,dst);  
        }
        ans.push_back(start);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map <string,deque<string>> adj;
        for(auto &k: tickets){
            adj[k[0]].push_back(k[1]);
        }
        for(auto& [u,v]: adj){
            sort(v.begin(),v.end(),greater<string>());
        }
        vector<string> ans;
        dfs(adj,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
