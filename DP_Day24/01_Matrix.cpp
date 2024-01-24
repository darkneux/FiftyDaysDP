class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int inf = 1e8;
        for(int i = 0;i < n;++i){
            for(int j =0;j < m;++j){
                dp[i][j]=mat[i][j];
            }
        }

        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
               if(mat[i][j]==0)continue;
               int u = inf, l = inf;
               if(i > 0)u = dp[i-1][j];
               if(j > 0)l = dp[i][j-1];
               dp[i][j] = min(u,l)+1;  
            }
        }

        for(int i = n-1;i >=0 ;--i){
            for(int j = m-1;j >=0;--j){
                if(mat[i][j]==0)continue;
                int d = inf, r = inf;
                if(i < n-1)d = dp[i+1][j];
                if(j < m-1)r = dp[i][j+1];
                dp[i][j] = min(min(d,r)+1,dp[i][j]); 
            }
        }
        return dp;

    }
};
