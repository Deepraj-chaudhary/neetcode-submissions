class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), totgas=accumulate(gas.begin(),gas.end(),0);
        int totcost=accumulate(cost.begin(),cost.end(),0);

        if(totgas<totcost) return -1;
        int curr=0, idx=0;
        for(int i=0;i<n;i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                idx=i+1;
                curr=0;
            }            
        }
        return idx;
    }
};
