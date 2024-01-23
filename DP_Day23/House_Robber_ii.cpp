class Solution {
public:
 int help_rob(vector<int>& nums,int st ,int ed) {
         int  pwith_rob = 0, pwiot_rob = 0;
        for(int i = st;i < ed;++i){
            int twith_rob = pwiot_rob+nums[i];
            int twiot_rob = max(pwith_rob,pwiot_rob);
            pwith_rob = twith_rob;
            pwiot_rob = twiot_rob;
        }
        return max(pwith_rob,pwiot_rob);
 }
        
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return max(help_rob(nums,0,nums.size()-1),help_rob(nums,1,nums.size()));
    }
};
