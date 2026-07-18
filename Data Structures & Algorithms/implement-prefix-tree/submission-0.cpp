class TrieNode{
public:
    unordered_map<char,TrieNode*> c;
    bool isend = false;
};
class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (const auto v : word){
            if (node->c.find(v)!=node->c.end()){
                node = node->c[v];
            }
            else {
                node->c[v] = new TrieNode();
                node = node->c[v];
            }
        }
        node->isend = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (const auto v : word){
            if (node->c.find(v)!=node->c.end()){
                node = node->c[v];
            }
            else {
                return false;
            }
        }
        if (node->isend == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (const auto v : prefix){
            if (node->c.find(v)!=node->c.end()){
                node = node->c[v];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
