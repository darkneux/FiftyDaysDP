class Solution {
public:
    int fun(string &word1, string &word2,vector<vector<int>>&dp,int i,int j) {
        // if (word1.size() == i && word2.size() == j) return 0;
        if (i >= word1.size()) return word2.size()-j;
        if (j >= word2.size()) return word1.size()-i;

        int minv = 1e8;
        if(dp[i][j]!=-1)return dp[i][j];

        if (word1[i] == word2[j]) {
            minv = fun(word1, word2,dp,i+1,j+1); // first char same hai
        } else {
            int a = fun(word1,word2,dp,i+1,j+1); //replace kiya hai
            int b = fun(word1,word2,dp,i+1,j);  //delete kiya hai
            int c = fun(word1,word2,dp,i,j+1);  //insert kiya hai
            minv = min({a,b,c})+1; 
        }
        dp[i][j] = minv;
        return minv;
    }

    int minDistance(string word1, string word2) {
        if(!word1.size())return word2.size();
        if(!word2.size())return word1.size();
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return fun(word1, word2,dp,0,0);
    }
};
