class Solution {
public:
    int fun(vector<int>&arr,int i,int k,vector<int>&dp){
        int n = arr.size();
        if(i >= n)return 0;
        if(dp[i]!=-1)return dp[i];
        int mans = 0;
        int max = INT_MIN;

        for(int j = i;j < min(n,(i+k)) ;++j){
            maxir = max(maxir,arr[j]);
            int withcon = fun(arr,j+1,k,dp)+(maxir*(j-i+1));
            mans = max(mans,withcon);
        }

        return dp[i] = mans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

      vector<int>dp(arr.size(),-1);
        return fun(arr,0,k,dp); 

    }
};
