class Solution {
public:
    unordered_set<int> e;
    int start =-1;
    bool dfs(vector<vector<int>>& adj,vector<bool> &visited,int i,int p){
        if(visited[i]){
            start = i;
            e.insert(i);  
            return true;
        }
        visited[i] = true;
        for(const auto v: adj[i]){
            if(v==p) continue;
            if(dfs(adj,visited,v,i)){
                if(i == start){
                    return false;
                }
                if(start != -1){
                    e.insert(i);
                    return true;
                }
                return false;
            } 
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(adj,visited,1,-1);
        for(int i = n-2; i>=0; i--){
            if(e.count(edges[i][0]) && e.count(edges[i][1])){
                return {edges[i][0],edges[i][1]};
            }
        }
        return {0,0};
    }
};
