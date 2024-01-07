class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long ,long long>> dp(n);
        long long sum = 0;
        for(int i = 1;i < n;++i){
            for(int j = i-1; j >= 0;j--){
                long long t = 1;    
                long long diff =  (long long)nums[j] - (long long)nums[i];
                if(dp[j].find(diff) != dp[j].end())t+=dp[j][diff];
                dp[i][diff]+=t;
                sum+=t;
            }
        }
        int ans = sum - (n*(n-1)/2);
        return ans;
    }
};
