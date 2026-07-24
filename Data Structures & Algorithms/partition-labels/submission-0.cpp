class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size(),idx=0,prev=0;
        vector<int> ans,end(26,0);
        for(int i =0; i<n; i++){
            end[s[i]-'a']=i;
        }
        for(int i =0; i<n; i++){
            idx=max(idx,end[s[i]-'a']);

            if(idx == i){
                ans.push_back(idx-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};
