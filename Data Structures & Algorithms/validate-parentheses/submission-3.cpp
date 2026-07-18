class Solution {
public:
    char op(char c){
        if(c==')') return '(';
        if(c=='}') return '{';
        if(c==']') return '[';
        return 'f';
    }
    bool isValid(string s) {
        int n = s.size();
        if (n%2!=0) return false;
        stack<int> st;
        for (const auto c : s){
            if (c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()==op(c)){
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        if (st.empty())
        return true;
        return false;
    }
};
