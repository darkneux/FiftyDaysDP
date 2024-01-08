class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0]=nums[0];
        dp2[n-1]=nums[n-1];
        
        for(int i = 1;i < n;++i){
            if(nums[i])dp1[i]=dp1[i-1]+1;
            else dp1[i]=0;
        }
        for(int i = n-2;i >=0;--i){
            if(nums[i])dp2[i]=dp2[i+1]+1;
            else dp2[i]=0;
        }
        int ans = 0;
        for(int i = 0;i < n;++i){
            int sum=0;
            if(i > 0)sum+=dp1[i-1];
            if(i < n-1)sum+=dp2[i+1];
            ans = max(ans,sum);
        }
       
        return ans;
        
    }
};
