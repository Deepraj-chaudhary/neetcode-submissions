class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int i){
        int cur = i;
        while (cur != parent[cur]){
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        return cur;
    }

    bool unionset(int a,int b){
        int pa = find(a), pb=find(b);
        if (pa==pb) return false;
        else {
            if (rank[pa]>rank[pb]){
                parent[pb]=parent[pa];
            }
            else if (rank[pa]<rank[pb]){
                parent[pa]=parent[pb];
            }
            else {
                rank[pb]++;
                parent[pa]=parent[pb];
            }
            return true;
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = n;
        DSU d(n);
        for (const auto &v: edges){
            if (d.unionset(v[0],v[1])) cnt--;
        }
        return cnt;
    }
};
