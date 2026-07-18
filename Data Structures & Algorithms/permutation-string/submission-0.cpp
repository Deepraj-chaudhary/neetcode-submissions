class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),   m= s2.size();
        if(n>m) return false;
        vector <int> freq(26,0);
        int matches = 26;
        for(int i=0; i<n ; i++){
            if(freq[s1[i]-'a']--) {
                if(!freq[s1[i]-'a']) matches ++;
            }
            else{
                matches --;
            }
            if(freq[s2[i]-'a']++) {
                if(!freq[s2[i]-'a']) matches ++;
            }
            else{
                matches --;
            }
        }
        if( matches == 26) return true;
        for(int i=n; i<m; i++){
            if(freq[s2[i-n]-'a']--) {
                if(!freq[s2[i-n]-'a']) matches ++;
            }
            else{
                matches --;
            }
            if(freq[s2[i]-'a']++) {
                if(!freq[s2[i]-'a']) matches ++;
            }
            else{
                matches --;
            }
            if( matches == 26) return true;
        }
        return false;        
        
    }
};
