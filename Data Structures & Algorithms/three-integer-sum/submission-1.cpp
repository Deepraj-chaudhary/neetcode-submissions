class Solution {
public:
    #define fr(i,n) for(int i=0;i<n;i++)
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,vector<pair<int,int>>> m;
        int n= nums.size();
        fr(i,n-1){
            for(int j=i+1;j<n;j++){
                int a= nums[i],b=nums[j];
                int key= a+b;          
                m[key].push_back({i,j});
            }
        }
        set <vector<int>> ans;
        fr(i,n){
            int key = -nums[i];
            if(m.find(key)!=m.end()){
            vector <pair<int,int>> &a = m[key];
            for(const auto& p: a){
                if(i==p.first || i==p.second) continue;
                vector <int> k= {nums[i],nums[p.first],nums[p.second]};
                sort(k.begin(),k.end());
                ans.insert(k);
            }
            }
        }

        return vector<vector<int>> (ans.begin(),ans.end());
    
    }
};
