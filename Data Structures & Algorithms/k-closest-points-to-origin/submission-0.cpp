class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> h;
        for (int i = 0; i<points.size();i++){
            int dist = pow(points[i][0],2)+pow(points[i][1],2);
            h.push({dist,i});
            if (h.size()>k) h.pop();
            
        }
        vector<vector<int>> ans;
        while (!h.empty()){
            int i = h.top().second;
            h.pop();
            ans.push_back(points[i]);
        }
        return ans;
    }
};
