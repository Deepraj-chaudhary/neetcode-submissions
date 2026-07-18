class Solution {
public:
    #define N 2147483647
    void bfs(vector<vector<int>>& grid,deque <pair<int,int>> &q){
        vector<vector<int>> dirn = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [row,col] = q.front();
            for(const auto v: dirn){
                int r = row+v[0],c =col+v[1];
                if (r<grid.size() && r>=0 && c<grid[r].size() && c>=0 && grid[r][c]==N){
                    grid[r][c]=grid[row][col]+1;
                    q.push_back({r,c});
                }
            }
            q.pop_front();
        }
        return;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        deque <pair<int,int>> q; 
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[i].size();j++){
                if (grid[i][j]==0) q.push_back({i,j});
            }
        }
        bfs(grid,q);
        return;
    }
};
