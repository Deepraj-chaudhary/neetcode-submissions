class Solution {
public:
    #define N 1
    int maxm = 2;
    void bfs(vector<vector<int>>& grid,deque <pair<int,int>> &q){
        vector<vector<int>> dirn = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [row,col] = q.front();
            for(const auto v: dirn){
                int r = row+v[0],c =col+v[1];
                if (r<grid.size() && r>=0 && c<grid[r].size() && c>=0 && grid[r][c]==N){
                    grid[r][c]=grid[row][col]+1;
                    maxm= max(maxm,grid[r][c]);
                    q.push_back({r,c});
                }
            }
            q.pop_front();
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        deque <pair<int,int>> q; 
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[i].size();j++){
                if (grid[i][j]==2) q.push_back({i,j});
            }
        }
        bfs(grid,q);
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[i].size();j++){
                if (grid[i][j]==N) return -1;
            }
        }
 
        return maxm-2;
    }
};
