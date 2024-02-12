class Solution {
   public:

    int fun(int n, vector<int>&ans){
        if(n==0||n==1)return n;
        
        if(ans[n] != 0) return ans[n]; 

        if(n % 2 == 0) {
            ans[n] = fun(n / 2, ans);
            return fun(n / 2, ans);
        }
        else {
            ans[n] = 1 + fun(n / 2, ans);
            return 1 + fun(n / 2, ans);
        } 
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1,0); 
        
        for(int i = 0; i <= n; i++){ 
            ans[i] = fun(i, ans);
        }
        return ans;
    }
     
};
