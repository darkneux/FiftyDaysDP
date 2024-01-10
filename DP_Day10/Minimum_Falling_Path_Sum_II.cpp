class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int j = 0;j < n;++j)dp[n-1][j] = matrix[n-1][j];
        for(int i = n-2; i >= 0;--i){
            for(int j = 0;j < n;++j){
                int minv = 1e9;
                for(int k = 0;k < n;++k){
                    if(k==j)continue;
                    minv = min(minv,dp[i+1][k]);
                }
                dp[i][j]=minv+matrix[i][j];
            }
        }

        int ans = 1e9;
        for(int j = 0;j < n;++j)ans = min(ans,dp[0][j]);
        return ans;
    }
};
