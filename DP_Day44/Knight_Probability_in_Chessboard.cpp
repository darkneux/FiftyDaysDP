class Solution {
public:
    bool isvalid(int n,int r,int c){
        return r>=0&&r<n&&c>=0&&c<n;
    }
    void cleardp(int n, bool f,vector<vector<vector<double>>>&dp){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
               dp[i][j][f]=0;
            }
        }
    }
    void printdp(int n,bool f,vector<vector<vector<double>>>&dp){
        cout<<"["<<endl;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
               cout<<dp[i][j][f]<<" ";
            }
            cout<<endl;
        }
        cout<<"]"<<endl;
    }
    double knightProbability(int n, int k, int row, int column) {

        vector dp(n,vector<vector<double>>(n,vector<double>(2,0.0)));
        vector<vector<int>> moves{
            {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}
        };
      
        
        dp[row][column][0]=(double)1.0;
        // printdp(n,0,dp);
        bool f= 1;
        
        while(k--){ 
            // cout<<f<<endl;
        //   printdp(n,f,dp);
          for(int i = 0;i < n;i++){
              for(int j = 0;j < n;j++){
                  if(dp[i][j][!f] > (double) 0){
                    //   cout<<"hi"<<i<<" "<<j<<endl;
                     for(auto &move : moves){
                         int rnext = i+move[0],cnext = j+move[1];
                         if(isvalid(n,rnext,cnext)){
                              dp[rnext][cnext][f] += (double)dp[i][j][!f]/8.0;
                         }
                     }
                  }
              }
          }
        //  printdp(n,f,dp);
         cleardp(n,!f,dp);

          f=!f;
        }
        double ans = 0.0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                ans+=dp[i][j][!f];
            }
        }
        return ans;
        
    }
};
