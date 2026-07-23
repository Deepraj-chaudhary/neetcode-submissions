class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize!=0) return false;
        map <int,int> m;
        for(int h: hand){
            m[h]++;
        }
        vector<int> grp(groupSize,-1);
        int i=0,j=0;
        for(auto [card,freq]:m){
            if(freq>0){
                for(int i=0;i<groupSize;i++){
                    if(m[card+i]<freq) return false;
                    m[card+i]-=freq;
                }
            }
        }
        return true;
    }
};
