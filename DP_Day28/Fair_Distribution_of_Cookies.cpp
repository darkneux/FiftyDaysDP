class Solution {
public:
    int fun(vector<int>&cookies,int cinx, vector<int>&dp){
        if(cinx==cookies.size()){
            return *max_element(dp.begin(),dp.end());
        }
        int mans = INT_MAX;
        for(int i = 0;i < dp.size();++i){
            dp[i]+=cookies[cinx];
            mans = min(mans,fun(cookies,cinx+1,dp));
            dp[i]-=cookies[cinx];
        }
        return mans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>dp(k,0);
        return fun(cookies,0,dp);
    }
};
