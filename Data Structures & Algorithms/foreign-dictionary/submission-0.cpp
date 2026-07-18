class Solution {
public:
    string foreignDictionary(vector<string>& words){
        
        int n = words.size();
        unordered_map<char,set<char>> adj;
        unordered_map<char,int> indegree; 
        for(auto v : words){
            for(auto u:v){
                indegree[u]=0;
                adj[u]=set<char>();
            }
        }
        for (int i = 1;i<n;i++){
            int m = min(words[i].size(),words[i-1].size());
            for(int j=0; j<m ;j++){
                if(words[i][j] != words[i-1][j]){
                    if(adj[words[i-1][j]].insert(words[i][j]).second) indegree[words[i][j]]++;
                    break;
                }
                if (words[i-1].size()>words[i].size() && j==m-1) return "";
            }
        }
        deque<char> q; 
        for(auto [v,cnt] : indegree){
            if(!cnt) q.push_back(v);
        }
        string ans = "";
        while(!q.empty()){
            char c = q.front();
            q.pop_front();
            ans += c;
            for(auto u: adj[c]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push_back(u);
                }
            }
        }
        return ans.size() == indegree.size()? ans:"";
    }
};
