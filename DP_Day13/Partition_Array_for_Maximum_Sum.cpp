class Solution {
public:

    int fun(vector<int>&arr,int i,int k,vector<int>&dp){
        if(i >= arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int mans = 0;
        int maxir = INT_MIN;
        int ecount = 0;
        int n = arr.size();
        for(int l = i;l < min(n,(i+k)) ;++l){
            ecount++;
            maxir = max(maxir,arr[l]);
            int withcon = fun(arr,l+1,k,dp)+(maxir*ecount);
            mans = max(mans,withcon);
        }
        return dp[i] = mans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return fun(arr,0,k,dp);
    }
};
