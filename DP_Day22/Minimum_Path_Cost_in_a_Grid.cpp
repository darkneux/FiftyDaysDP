class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int j = 0;j < m;++j) dp[n-1][j] = grid[n-1][j];
        for(int i = n-2;i >= 0;--i){
            for(int j = 0;j < m;++j){
                int minv = INT_MAX;
                for(int k = 0;k < m;++k)  minv = min(grid[i][j]+dp[i+1][k]+moveCost[grid[i][j]][k],minv);
                dp[i][j]=minv;
            }
        }
        return  *min_element(dp[0].begin(),dp[0].end());
    }
};
