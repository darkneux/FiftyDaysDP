class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<bool> ans(n,false); ans[n-1]=true;
        int lt = n-1;
        for(int i = n-2;i >= 0;i--){
            if(nums[i]+i >= lt){
                // ans[i]=true;
                lt=i;
            }
        }
        return lt==0; 
        
    }
};
