class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        array<bool, 3> ans = {false, false, false};
        int a = target[0],b=target[1],c=target[2];
        for(auto &v:triplets){
            int ai= v[0],bi=v[1],ci=v[2];
            if(ai<=a && bi<=b &&ci<=c){
                ans[0] = ans[0] || (ai == a);
                ans[1] = ans[1] || (bi == b);
                ans[2] = ans[2] || (ci == c);
            }
        }
        return ans[0] && ans[1] && ans[2];
    }
};
