class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int n, int m, int r, int c1, int c2, vector<vector<vector<int>>>& dp) {
        if (r < 0 || r >= n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) return 0;

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int maxc = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newCol1 = c1 + i;
                int newCol2 = c2 + j;
                maxc = max(maxc, dfs(grid, n, m, r + 1, newCol1, newCol2, dp));
            }
        }

        int cc = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];

        dp[r][c1][c2] = cc + maxc;
        return dp[r][c1][c2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return dfs(grid, n, m, 0, 0, m - 1, dp);
    }
};
