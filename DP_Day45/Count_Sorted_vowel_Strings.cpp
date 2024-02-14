class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(5,vector<int>(n+1,1));
        int  count = 5;
        for(int i = 0;i < 5;i++){dp[i][1]=count;count--;}
        for(int j = 2;j <= n;++j){
            for(int i = 0;i < 5;++i){
                int sum = 0;
                for(int k = i;k < 5;++k){
                    sum+=dp[k][j-1];
                }
                dp[i][j] = sum;
            }
        }
       
     return dp[0][n];  
    }
};
	
