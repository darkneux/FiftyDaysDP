class Solution {
public:
    
    int fun(vector<int>&piles,int i,int j,bool f,vector<vector<int>>&dp){
        if(i > j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(f)return dp[i][j]= max(fun(piles,i+1,j,!f,dp)+piles[i],fun(piles,i,j-1,!f,dp)+piles[j]);
        return dp[i][j] = min(fun(piles,i+1,j,!f,dp)+piles[i],fun(piles,i,j-1,!f,dp)+piles[j]);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        int total = 0;
        for(int i = 0;i < piles.size();++i)total+=piles[i];

        int alice =  fun(piles,0,piles.size()-1,true,dp);
        int bob = total-alice;
        return alice > bob;

    }
};
