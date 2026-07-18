class Solution {
public:
    void solve(vector<vector<string>> &ans,vector<string> &cur,int col,int ld,int rd,int i){
        int n = cur.size();
        if (i >= n){
            ans.push_back(cur);
            return;
        }

        for(int j=0;j<n;j++){
            if ((col & (1<<j)) || (rd & (1<<(i+j))) || (ld & (1<<(i - j + n)))) continue;
            
            cur[i][j] = 'Q';
            col = (col | (1<<j));
            rd = (rd | (1<<(i+j))); 
            ld = (ld | (1<<(i - j + n)));
            solve(ans,cur,col,ld,rd,i+1);
            col = (col ^ (1<<j));
            rd = (rd ^ (1<<(i+j)));
            ld = (ld ^ (1<<(i - j + n)));
            cur[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n,string(n,'.'));
        
        int col = 0,ld=0,rd=0;
        solve(ans,curr,col,ld,rd,0);
        return ans;
    }
};
