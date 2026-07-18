class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int &cnt){
        if (grid[i][j]==0) return;
        grid[i][j]=0;
        if (i-1>=0) dfs(grid,i-1,j,cnt);
        if (i+1<grid.size()) dfs(grid,i+1,j,cnt);
        if (j-1>=0) dfs(grid,i,j-1,cnt);
        if (j+1<grid[i].size()) dfs(grid,i,j+1,cnt);
        cnt++;
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0;i<grid.size();i++){
            for (int j= 0;j<grid[i].size();j++){
                int cnt = 0;
                dfs(grid,i,j,cnt);
                if(cnt) ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
