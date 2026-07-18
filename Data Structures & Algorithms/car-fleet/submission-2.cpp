class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector <pair<int,int>> pos(n);
        for (int i = 0; i<n;i++){
            pos[i]= {position[i],speed[i]};
        }
        sort(pos.begin(),pos.end(),[](pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
        });
        int ans = n;
        int currdist = (target-pos[n-1].first), currs = pos[n-1].second;
        for (int i = n-2; i>=0 ;i--){
            if ((target-pos[i].first)*currs <= currdist*pos[i].second){
                ans--;
                //currdist = (target-pos[i+1].first); currs = pos[i+1].second;
            }
            else{
                currdist = (target-pos[i].first); currs = pos[i].second;
            }
        }
        return ans;
    }
};
