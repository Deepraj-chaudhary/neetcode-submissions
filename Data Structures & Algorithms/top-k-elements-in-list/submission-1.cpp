class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> m;
        for(int i=0; i<nums.size(); i++){
                m[nums[i]]++;
        }
        vector <pair<int,int>> sorted;
        for (const auto& [key,value] : m){
            sorted.push_back({value,key});
        }
        sort(sorted.begin(),sorted.end(),greater<pair<int,int>>());
        vector <int> ans(k);
        for (int i=0; i<k; i++){
          
            ans[i]= sorted[i].second;
        }
        return ans;
    }
};
