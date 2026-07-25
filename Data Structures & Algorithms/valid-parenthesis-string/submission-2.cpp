class Solution {
public:
    bool checkValidString(string s) {
    int omax=0,omin=0;
        for(char c:s){
            if(c=='('){
                omax++;
                omin++;
            }
            if(c==')'){
                omax--;
                omin--;
            }
            if(c=='*'){
                omax++;
                omin--;
            }
            if(omax<0) return false;
            omin=max(omin,0);
        }
        return omin==0;
    }
};
