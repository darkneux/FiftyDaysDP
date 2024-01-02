class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int start = obstacleGrid[0][0];
        int dp[n][m];
        dp[0][0] = !start;
        for(int i = 1;i < n;i++) dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i-1][0];
        for(int j = 1;j < m;j++) dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j-1];
        for(int i = 1; i < n;++i){
            for(int j = 1;j < m; ++j){
               dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
     return dp[n-1][m-1];   
    }
};
