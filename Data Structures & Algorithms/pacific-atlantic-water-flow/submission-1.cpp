class Solution {
public:
    int N = 0;
    void bfs(vector<vector<bool>>& grid,vector<vector<int>>& heights,deque <pair<int,int>> &q){
        vector<vector<int>> dirn = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [row,col] = q.front();
            for(const auto v: dirn){
                int r = row+v[0],c =col+v[1];
                if (r<heights.size() && r>=0 && c<heights[r].size() && c>=0 && !grid[r][c] && heights[r][c]>=heights[row][col]){
                    grid[r][c] = true;
                    q.push_back({r,c});
                }
            }
            q.pop_front();
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> grid(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> grid2(heights.size(),vector<bool>(heights[0].size(),false));
        deque <pair<int,int>> q;
        for(int i = 0; i<heights.size();i++){
            q.push_back({i,0});
            grid[i][0]=true;
        }
        for(int i = 0; i<heights[0].size();i++){
            q.push_back({0,i});
            grid[0][i]=true;
        }
        bfs(grid,heights,q);
        N++;
        for(int i = 0; i<heights.size();i++){
            q.push_back({i,heights[0].size()-1});
            grid2[i][heights[0].size()-1]=true;
        }
        for(int i = 0; i<heights[0].size();i++){
            q.push_back({heights.size()-1,i});
            grid2[heights.size()-1][i]=true;
        }
        bfs(grid2,heights,q);
        vector<vector<int>> ans;
        for(int i = 0; i<heights.size();i++){
            for(int j = 0; j<heights[0].size();j++){
                if(grid[i][j] && grid2[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
