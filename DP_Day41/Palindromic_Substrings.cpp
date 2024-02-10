class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int i = 0;
        int ans = n;
        for(int j = 0;j < n;++j){
            int k = i;
            int l = j;
            while(l < n && k < n){
                if(l==k){
                    dp[k++][l++]=1;
                }else{
                    if(s[l]==s[k]&&(abs(l-k)==1 || dp[k+1][l-1])){
                        dp[k++][l++]=1;
                        ans++;
                    }else{
                        dp[k++][l++]=0;
                    }
                }
            }
        }
        
        // for(auto &it : dp){
        //     for(auto v:it){
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;

    }
};
