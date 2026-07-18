class Solution {
public:
    bool isPalindrome(string s) {
        deque<int> d;
        for(auto c: s){
            if((c-'a'>=0 && c-'a'<26) || (c-'A'>=0 && c-'A'<26) || (c-'0'>=0 && c-'0'<10)){
                d.push_back((char)tolower(c));
            }
        }
        while(!d.empty()){
            if(d.front()!=d.back()){
                return false;
            }
            if(d.size()==1) {break;}
            d.pop_front(); d.pop_back();

        }
        return true;
    }
};
