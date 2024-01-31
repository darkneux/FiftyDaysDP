class Solution {
public:
    // int count = 0;
    int fun(string &s , int i,int j,vector<vector<int>>&dp){
        if(i >= j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        // count++;
        if(s[i]==s[j])
          return fun(s,i+1,j-1,dp);
        else
          return dp[i][j] = min(fun(s,i+1,j,dp),fun(s,i,j-1,dp))+1;
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(s,0,n-1,dp);
    }
};
