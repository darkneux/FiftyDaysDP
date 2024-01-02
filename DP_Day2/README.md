# 62. Unique Paths
### Medium

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

*Example 1:*

- Input: m = 3, n = 7
- Output: 28

*Example 2:*

- Input: m = 3, n = 2
- Output: 3
- Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
   1. Right -> Down -> Down
   2. Down -> Down -> Right
   3. Down -> Right -> Down

*Constraints:*

- 1 <= m, n <= 100

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,1));
        for(int i = 1; i < n;++i){
            for(int j = 1;j < m; ++j){
               dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

```

#### Time Complexity : `O(n^2)`
#### Space Complexity : `O(n^2)`



## --------------------------------------------------------------------------------------------------

# 63. Unique Paths II
### Medium

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9

*Example 1:*

- Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
- Output: 2
- Explanation: There is one obstacle in the middle of the 3x3 grid above.
  There are two ways to reach the bottom-right corner:
  1. Right -> Right -> Down -> Down
  2. Down -> Down -> Right -> Right

*Example 2:*

- Input: obstacleGrid = [[0,1],[0,0]]
- Output: 1

*Constraints:*

- m == obstacleGrid.length
- n == obstacleGrid[i].length
- 1 <= m, n <= 100
- obstacleGrid[i][j] is 0 or 1.

```cpp
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
```
#### Time Complexity : `O(n^2)`
#### Space Complexity : `O(n^2)`
