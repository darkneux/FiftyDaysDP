class Solution {
public:
    int fun(vector<int>&s , int i ,int t,vector<vector<int>>&dp){
        if(i+1 == s.size()){
            return s[i] > 0 ? s[i]*t : 0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int maxv = 0;
        maxv = max(maxv,fun(s,i+1,t+1,dp)+s[i]*t);
        maxv = max(maxv,fun(s,i+1,t,dp));
        return dp[i][t] = maxv;
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
        return fun(s,0,1,dp);
    }
};
