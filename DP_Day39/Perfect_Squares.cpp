class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0; dp[1]=1;
        for(int i = 2;i <= n;++i){
            int sq = sqrt(i);
            int ans = 1e8;
            for(int k = 1; k <= sq;++k){
                int v = pow(k,2);
                int val = i - v;
                ans = min(ans,dp[val]);
            }
            ans+=1;
            dp[i]=ans;
        }
        return dp[n];
    }
};
