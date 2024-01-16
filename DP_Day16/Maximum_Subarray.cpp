class Solution {  //Dynamic Programming Solution
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n));
        
        dp[0][n-1] = nums[n-1];
        dp[1][n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i+1]);
            dp[0][i] = max(dp[0][i+1], dp[1][i]);
        }
        return dp[0][0];
    }
};

/*
class Solution {  //Kadane's Algo
public:
    int maxSubArray(vector<int>& nums) {
        int Gmax = 0;
        int Lmax = 0;
        int mneg = INT_MIN;
        bool f = false;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] > 0) f=true;
            mneg = max(mneg,nums[i]);
            Lmax = Lmax+nums[i] > 0 ? Lmax+=nums[i] : 0;
            Gmax = max(Gmax,Lmax);
        }
        return !f ? mneg : Gmax ;
    }
};

*/
