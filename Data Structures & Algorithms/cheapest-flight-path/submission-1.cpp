class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> cost(n,INT_MAX);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].emplace_back(flights[i][1],flights[i][2]);
        }
        queue<tuple<int,int,int>> q;
        q.push({0,src,0});
        cost[src] = 0;
        while(!q.empty()){
            auto [c,curr,stops] = q.front();
            q.pop();
            if(stops>k) continue;
            for(auto v:adj[curr]){
                int nextdist = c + v.second;
                if(nextdist<=cost[v.first]){
                    cost[v.first] = nextdist;
                    q.push({nextdist,v.first,stops+1});
                }
            }
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
