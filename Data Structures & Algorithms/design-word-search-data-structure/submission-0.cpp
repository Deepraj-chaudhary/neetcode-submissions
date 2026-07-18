class WordDictionary {
private:
    struct Trie{
        unordered_map<char,Trie*> c;
        bool isend = false;
    };
    Trie* root;
public:
    
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie * curr = root;
        for(const auto v : word){
            if(curr->c.find(v)==curr->c.end()){
                curr->c[v] = new Trie();
            }
            curr = curr->c[v];
        }
        curr->isend = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
    bool dfs(string &word,int i,Trie *r){
        if (i == word.size()){
            return r->isend;
        }

        char v = word[i];

        if (v != '.'){
            if(r->c.find(v)==r->c.end()){
                return false;
            }
            return dfs(word,i+1,r->c[v]);
        }
        for(const auto &n : r->c){
            if(dfs(word,i+1,n.second)) return true;
        }
        return false;
    }
};
