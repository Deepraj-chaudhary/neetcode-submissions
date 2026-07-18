class Solution {
private:
    vector<string> ans;
public:
    void solve(int n,string &s,int o,int c){
        if (s.size() == 2*n){
            ans.push_back(s);
        }
        
        if (o<n){
            (s) += "(";
            solve(n,s,o+1,c);
            (s).pop_back();
        }
        if (c<n && o>c){
            (s) += ")";
            solve(n,s,o,c+1);
            (s).pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s;
        solve(n,s,0,0);
        return ans;
    }
};
