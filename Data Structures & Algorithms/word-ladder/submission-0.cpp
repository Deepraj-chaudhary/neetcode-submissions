class Solution {
public:
    int n,m;
    unordered_set <string> s;
    int bfs(string beginWord,string &endWord){
        deque <string> q = {beginWord};
        int ans = 1;
        unordered_set <string> visited;

        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                string w = q.front();
                visited.insert(w);
                if(w==endWord) return ans;

                for(int k=0;k<m;k++){
                    for(int j=0;j<26;j++){
                        char c = w[k];
                        w[k] =('a'+j);
                        if(s.count(w) && !visited.count(w)){
                            q.push_back(w);
                        }
                        w[k] = c;
                    }
                }
                q.pop_front();
            }
            ans++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        m = beginWord.size();
        n = wordList.size();
        for (int j = 0; j<n; j++){
            // for(int i=0;i<m;i++){
            //     char c = wordList[j][i];
            //     wordList[j][i] ='*';
                s.insert(wordList[j]);
            //     wordList[j][i] = c;
            // }
        }
        return bfs(beginWord,endWord);
    }
};
