class Solution {
public:

    void solve(vector<string> &ans,vector<string> &s,string &curr,int i,string &digits){
        if (i>=digits.size()){
            ans.push_back(curr);
            return;
        }
        int j = digits[i] - '0';
        for (const auto v : s[j]){
            curr+=v;
            solve(ans,s,curr,i+1,digits);
            curr.pop_back();
        }
        return;

    }
    vector<string> letterCombinations(string digits) {
        vector<string> s(10,"");
        for(int i = 0,curr=0,j=2; i<26; i++,curr++){
            if ((j!=7 && j!=9) && curr == 3){
                j++; curr = 0;
            }
            else if (curr == 4){
                j++; curr = 0;
            }
            s[j] += (char)('a' + i);
        }
        vector<string> ans;
        string curr;
        if (digits.size()!=0) solve(ans,s,curr,0,digits);

        return ans;
    }
};
