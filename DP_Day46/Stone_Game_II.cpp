class Solution {
public:
    int fun(vector<int>&piles,int i ,int m,bool f,vector<vector<vector<int>>>&dp){
          if(i >= piles.size())return 0;
          if(dp[i][m][f]!=-1)return dp[i][m][f];
          int ans;
          if(f)ans=0;
          else ans=INT_MAX;
          int total = 0;
          for(int k = 1;k <= (2*m);++k){
              if(i+k > piles.size())break;
              total+=piles[i+k-1];
              int a = fun(piles,i+k,max(k,m),!f,dp);
              if(f)ans = max(ans,a+total);
              else ans = min(ans,a);
          }
          return dp[i][m][f] = ans;
    } 
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size(),vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return fun(piles,0,1,true,dp);
    }
};
