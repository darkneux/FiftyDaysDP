class Solution {
public:
    int fun(vector<int>&prices ,int i,vector<int>&dp){
        if(i >= prices.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        for(int k = i+1; k <= (2*i)+2;k++){
            ans = min(ans,fun(prices,k,dp)+prices[i]);
        }
        return dp[i] = ans;
    }
    int minimumCoins(vector<int>& prices) {
        vector<int> dp(prices.size()+1,-1);
        return fun(prices,0,dp);
    }
};
