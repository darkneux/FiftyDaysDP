class Solution {
public:
    int calTrees(int n,vector<int> &dp){
       if(dp[n]!=-1)return dp[n];
       int midans = 0;
       for(int i = 1;i <= n;i++){
          midans+=(calTrees(i-1,dp)*calTrees(n-i,dp));
       }
       return dp[n] = midans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        return calTrees(n,dp);
    }
};
