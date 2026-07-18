class Solution {
public:
    #define ll int
    #define fr(i,n) for(ll i=0; i<n; i++)
    bool check(vector<ll> &a){
        fr(i,10){
            if(a[i]>1){
                return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        fr(i,9){
            vector <ll> a(10,0);
            fr(j,9){
                if(board[i][j]!='.'){
                    a[board[i][j]-'0']++;
                }
            }
            if(!check(a)){return false;}
            
        }
        fr(i,9){
            vector <ll> a(10,0);
            fr(j,9){
                if(board[j][i]!='.'){
                    a[board[j][i]-'0']++;
                }
            }
            if(!check(a)){return false;}
            
        }
        for(int k=0;k<9;k+=3){
            for(int p=0;p<9;p+=3){
                
                vector <ll> a(10,0);
                for(int i= k;i<k+3;i++){
                    for(int j=p;j<p+3;j++){
                        if(board[i][j]!='.'){
                            a[board[i][j]-'0']++;
                        }
                    }                                      
                }
                if(!check(a)){return false;}

            }
        }

        return true;
    }
};
