class Solution {
public:
    string longestPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); ++i)
            t += "#" + string(1, s[i]);
        t += "#";
        
        int n = t.size();
        vector<int> p(n, 0);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            p[i]=i<r?min(p[l+(r-i)],r-i):0;
            while (i+p[i]+1<n && i-p[i]-1>=0 && t[i+p[i]+1]==t[i-p[i]-1]){
                p[i]++;
            }
            if(p[i]*2>r-l){
                l=i-p[i];
                r=p[i]+i;
            }
        }
        int m=0;
        for(int i=0;i<n;i++){
            if(p[m]<p[i]) m=i;
        }
        l = (m - p[m])/2;
        return s.substr(l,p[m]);

    }
};
