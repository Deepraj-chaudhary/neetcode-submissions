class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if (n1 + n2 != n3) return false;
        vector<bool> curr(n2+1,false);
        curr[n2] = true; 
        
        for(int i=n1;i>=0;i--){
            for(int j=n2;j>=0;j--){
                int idx =i+j;
                if (i == n1 && j == n2) continue;
                if(i<n1 && s1[i]==s3[idx] && curr[j]){
                    curr[j]= true;                    
                }
                else if(j<n2 && s2[j]==s3[idx] && curr[j+1]){
                    curr[j] = true;
                }    
                else curr[j]= false;     
            }
        }
        return curr[0];
    }
};
