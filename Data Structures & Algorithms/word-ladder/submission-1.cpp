class Solution {
public:
    int n,m;
    unordered_map<string, vector<string>> mp;
    int bfs(string &beginWord,string &endWord){
        deque <pair<string,int>> q;
        q.push_back({beginWord,1});
        unordered_set<string> visited;

        while(!q.empty()){            
            auto [w,i] = q.front();
            visited.insert(w);
            if(w==endWord) return i;
            i++;
            for(int k=0;k<m;k++){
                char c = w[k];
                w[k] ='*';
                for(auto &v: mp[w]){
                    if(!visited.count(v)){
                        q.push_back({v,i});
                    }
                }
                mp[w].clear();
                w[k] = c;
            }
            q.pop_front();
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        m = beginWord.size();
        n = wordList.size();
        for (auto &word : wordList) {
            for(int i=0;i<m;i++){
                string pattern = word;
                pattern[i] ='*';
                mp[pattern].push_back(word);
            }
        }
        return bfs(beginWord,endWord);
    }
};
