class Solution {
public:
    bool ans = true;
    bool dfs(vector<vector<int>>& adj,vector<bool> &dist,int i,int p){
        if(dist[i]) return ans=false;
        dist[i] = true;
        bool res=true;
        for(const auto v: adj[i]){
            if(v==p) continue;
            res &= dfs(adj,dist,v,i);      
        }
        return  dist[i]=res;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> dist(n,false);
        vector<vector<int>> adj(n);
        for(auto v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(adj,dist,0,-1);
        for(auto v: dist){
            if(!v) return false;
        }
        return ans;
    }
};
