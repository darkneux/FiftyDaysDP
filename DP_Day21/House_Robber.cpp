class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), pwith_rob = 0, pwiot_rob = 0;
        for(int i = 0;i < nums.size();++i){
            int twith_rob = pwiot_rob+nums[i];
            int twiot_rob = max(pwith_rob,pwiot_rob);
            pwith_rob = twith_rob;
            pwiot_rob = twiot_rob;
        }
        return max(pwith_rob,pwiot_rob);
        
    }
};
