class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word, int i,int j, int k){
        if (word[k]==board[i][j]){
            if (k+1 == word.size()) return true;
            char c = board[i][j] ;
            board[i][j] = '1';
            bool ans = false;
            if (i-1>=0) ans = ans || solve (board,word,i-1,j,k+1);
            if (i+1<board.size()) ans = ans || solve (board,word,i+1,j,k+1);
            if (j-1>=0) ans = ans || solve (board,word,i,j-1,k+1);
            if (j+1<board[i].size()) ans = ans || solve (board,word,i,j+1,k+1);
            board[i][j] = c;
            return ans;
        }
        else return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for (int i = 0; i<board.size();i++){
            for (int j=0;j<board[i].size();j++){
                ans = ans || solve(board,word,i,j,0);
            }
        }
        return ans;
    }
};
