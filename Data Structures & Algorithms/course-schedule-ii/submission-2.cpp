class Solution {
public:
    vector<int> res;
    int dfs(vector<vector<int>>& adj,vector<int> &dist,int i){
        if(dist[i]==1 || dist[i]==-1) return -1;
        if(dist[i]==2) return 2;
        dist[i]=1;
        int ans = 2;
        for (const auto v: adj[i]){
            ans = min(dfs(adj,dist,v),ans);
        }
        if(ans==2) res.push_back(i);
        return dist[i] = ans;
    }
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> dist(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto v: prerequisites){
            // if(adj.size()>v[0]){
            //     ad[v[0]].push_back(v[1]);
            // }
            adj[v[0]].push_back(v[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(dfs(adj,dist,i)==-1) return {};
        }
        // for(int i=0;i<numCourses;i++){
        //     if(dist[i]==-1) return false;
        // }
        return res;
    }
};
