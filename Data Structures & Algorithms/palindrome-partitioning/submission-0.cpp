class Solution {
public:
    int fill(vector<vector<int>> &dp, int i, int j, string &s){
        if (dp[i][j]!=-1) return dp[i][j];
        if (i == j) return dp[i][j]=1;
        else if( i == j-1){
            if (s[i] == s[j]) return dp[i][j] = 1;
            else return dp[i][j] = 0;
        }
        else{
            if (s[i] == s[j] && fill(dp,i+1,j-1,s)) return dp[i][j] = 1;
            else return dp[i][j] = 0;
        }
        return 0;
    }
    void solve(vector<vector<string>> &ans,vector<string> &curr,vector<vector<int>> &dp,string&s,int i){
        if (i>=s.size()){ ans.push_back(curr);
        return;
        }

        for (int j = i; j<s.size(); j++){
            if (dp[i][j]){
                curr.push_back(s.substr(i,j-i+1));
                solve(ans,curr,dp,s,j+1);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                dp[i][j] = fill(dp,i,j,s);         
            }
        }
        vector<vector<string>> ans;
        vector<string> curr;
        solve(ans,curr,dp,s,0);
        return ans;

    }
};
