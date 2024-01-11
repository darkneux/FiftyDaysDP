class Solution {
public:
    int twoEggDrop(int n) {
     int k = 2;
     int dp[k+1][n+1];
        for(int j = 0;j <= n;++j)dp[1][j]=j;
        for(int i = 0;i <= k;++i){dp[i][0]=0;dp[i][1]=1;}
       
        for(int i = 2;i <= k;++i){
            for(int j = 2;j <= n;++j){
                int sval = 1e9;
                for(int k = 0;k < j; ++k){
                    int x = max(dp[i][j-1-k],dp[i-1][k]);
                    sval = min(x,sval);
                }
                dp[i][j]=sval+1;
            }
        } 
        return dp[k][n];   
    }
};
