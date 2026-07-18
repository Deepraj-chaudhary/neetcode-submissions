class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &v: times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
        q.push({0,k});

        vector<bool> visited(n+1,false);
        visited[0]=true;
        int t=0;
        while(!q.empty()){
            auto [w,j] = q.top();
            q.pop();
            if(visited[j]) continue;
            visited[j]=true;
            t=w;
            for (auto [i,d]: adj[j]){
                if(!visited[i]){
                    q.push({d+w,i});
                }
            }
        }
        for(auto v: visited){
            if(!v) return -1;
        }
        return t;   
    }
};
