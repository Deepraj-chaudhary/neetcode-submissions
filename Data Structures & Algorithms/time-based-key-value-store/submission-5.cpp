class TimeMap {
public:
    unordered_map <string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(m.find(key)==m.end()){
            vector <pair<int,string>> v;
            m[key]=v;
        }    
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";
        vector <pair<int,string>> v=m[key];
        int n=v.size();
        int l=0,r=n-1,ans=n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if (timestamp < v[mid].first) r=mid-1;
            else{
                ans = mid;
                l = mid+1;
            }
        }
        if (ans<n) return v[ans].second;
        return "";
    }
};
