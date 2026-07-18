class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    void dfs(vector<vector<char>> &board,vector<vector<bool>> &ans, int i,int j){
        if(board[i][j] == 'X' || ans[i][j]) return;
        ans[i][j] = true;
        for (auto v: dir){
            int r = i + v[0],c = j+ v[1];
            if (r>=0 && c>=0 && r<n && c<m){
                dfs(board,ans,r,c);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        deque<pair<int,int>> q;
        n = board.size(); 
        m = board[0].size();
        vector<vector<bool>> ans(n,vector<bool>(m,false));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if (i==0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]=='O') dfs(board,ans,i,j);
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!ans[i][j]) board[i][j]='X';
            }
        }

        return;
    }
};
