class TrieNode {
public:
    // FIX 1: Fixed-size array instead of unordered_map
    TrieNode* children[26] = {nullptr}; 
    bool is_word = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a'; // Convert char to 0-25 index
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->is_word = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        int maxLen = 0;
        
        for (string& word : wordDict) {
            trie.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }

        int n = s.length();
        
        // FIX 2: vector<char> completely bypasses the vector<bool> bit-packing penalty
        vector<char> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            TrieNode* node = trie.root;
            
            for (int idx = i; idx < min(n, i + maxLen); ++idx) {
                int charIndex = s[idx] - 'a';
                
                // Direct array access is infinitely faster than .count() on a map
                if (!node->children[charIndex]){
                    break; 
                }
                
                node = node->children[charIndex];
                
                if (node->is_word) {
                    dp[i] = dp[idx + 1];
                    if (dp[i]) break; 
                }
            }
        }

        return dp[0];
    }
};