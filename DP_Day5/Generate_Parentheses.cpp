class Solution {
public:
    void fun(int n,int o,int c,vector<string>&ans,string prop){
        if(o==n&&c==n){ans.push_back(prop);return;}
        if(o <= n)fun(n,o+1,c,ans,prop+"(");
        if(c < o)fun(n,o,c+1,ans,prop+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
       fun(n,0,0,ans,""); 
       return ans;
    }
};
