class Solution {
public:
    vector<pair<int,int>> dirn = {{1,0},{0,1},{-1,0},{0,-1}};
    int n;
    priority_queue <tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> q;
    int bfs(vector<vector<int>>& grid){
        int ans = 0;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        while(!q.empty()){
            auto [w,i,j] = q.top();
            visited[i][j]=true;
            q.pop();
            ans=max(ans,w);
            if (i==n-1 && j==n-1) return ans;

            for(auto [u,v]: dirn){
                int r = i+u,c=j+v;
                if (r>=0 && r<n && c<n && c>=0 && !visited[r][c]){
                    q.push({grid[r][c],r,c});
                }
            }
        }
        return ans;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        q.push({grid[0][0],0,0});
        return bfs(grid);
    }
};
