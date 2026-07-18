class Solution {
private:
struct Trie{
    unordered_map<char,Trie*> c;
    int cnt = 0;
    int isend = -1;
};
Trie* root =new Trie();
public:
    void addWord(string &word,int i) {
        Trie * curr = root;
        for(const auto v : word){
            curr->cnt++;
            if(curr->c.find(v)==curr->c.end()){
                curr->c[v] = new Trie();
            }
            curr = curr->c[v];
        }
        curr->cnt++;
        curr->isend = i;
    }

    int solve(vector<vector<char>>& board, vector<string>& words, vector<string> &res, int i,int j, Trie *node){
        if (board[i][j]=='1') return 0;
        int ans = 0;

        char c = board[i][j];
        if (node->c.find(c)!=node->c.end()) node = node->c[c];
        else return 0;
        if (node->isend != -1){
            res.push_back(words[node->isend]);
            node->isend = -1;
            ans++;
        }
        if (node->cnt>0){
            board[i][j] = '1';
            if (i-1>=0) ans += solve (board,words,res,i-1,j,node);
            if (i+1<board.size()) ans += solve (board,words,res,i+1,j,node);
            if (j-1>=0) ans += solve (board,words,res,i,j-1,node);
            if (j+1<board[i].size()) ans += solve (board,words,res,i,j+1,node);
            board[i][j] = c;
        }
        node->cnt-=ans;
        return ans;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i = 0; i<words.size(); i++){
            addWord(words[i],i);
        }

        vector<string> ans;

        for (int i = 0; i<board.size();i++){
            for (int j=0;j<board[i].size();j++){
                solve(board,words,ans,i,j,root);
            }
        }
        return ans;
    }
};



