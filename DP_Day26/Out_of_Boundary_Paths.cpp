class Solution {
public:
    int md= 1e9+7;
    vector<pair<int,int>> d={{-1,0},{0,-1},{1,0},{0,1}};
    int dp[51][51][51];
    int fun(int r,int c,int m,int n,int mm) {
        if(r==m || c==n || r==-1 || c==-1) return 1;
        if(mm==0) return 0;
        if(dp[r][c][mm]!=-1) return dp[r][c][mm];

        int ans=0;
        for(auto &[dx,dy] :d) {
            ans+=fun(r+dx,c+dy,m,n,mm-1);
            ans%=md;
        }
        return dp[r][c][mm]=ans; 
    }
    
    int findPaths(int m, int n, int mm, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return fun(sr,sc,m,n,mm);
    }
};
