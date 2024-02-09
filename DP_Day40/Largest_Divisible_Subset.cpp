class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,0);
        pair<int,int> maxv={-1*1e9,n-1};
        for(int i = n-1;i >= 0;--i){
            int v = nums[i];
            int m = 0;
            for(int j = i+1; j < n;++j){
                if(nums[j]%v == 0 ){
                    m = max(m,dp[j]+1);
                    if(dp[i] > maxv.first){
                        maxv.first = dp[i];
                        maxv.second = i;
                    }
                }
                dp[i]=m;
            }
        }
        // for(auto &val: nums)cout<<val<<" ";cout<<endl;
        // for(auto &val : dp)cout<<val<<" "; cout<<endl;
        
        vector<int>ans;
        ans.push_back(nums[maxv.second]);
        int count = dp[maxv.second];
        // cout<<count<<endl;
        for(int i = maxv.second+1;i < n;++i){
            if(nums[i]%ans[ans.size()-1]==0 && count-1==dp[i]){
                ans.push_back(nums[i]);
                count = dp[i];
            }
        }
        return ans;

    }
};
