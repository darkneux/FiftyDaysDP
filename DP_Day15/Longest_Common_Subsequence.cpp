class Solution {
public:
    int fun(string &t1,string &t2,int i ,int j,vector<vector<int>>&dp){
        if(i >= t1.size() || j >=t2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(t1[i]==t2[j])
            return fun(t1,t2,i+1,j+1,dp)+1;
            
        return dp[i][j] = max(fun(t1,t2,i+1,j,dp),fun(t1,t2,i,j+1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return fun(text1,text2,0,0,dp);
    }
};

