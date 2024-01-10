class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int j = 0;j < n;++j)dp[n-1][j] = matrix[n-1][j];
        for(int i = n-2; i >= 0;--i){
            for(int j = 0;j < n;++j){
                int l,p,q;
                l = j==0 ? INT_MAX : dp[i+1][j-1];
                p = dp[i+1][j];
                q = j==n-1 ? INT_MAX : dp[i+1][j+1];
                dp[i][j] = min({l,p,q})+matrix[i][j];
            }
        }
        int ans = 1e9;
        for(int j = 0;j < n;++j)ans = min(ans,dp[0][j]);
        return ans;
    }
};
