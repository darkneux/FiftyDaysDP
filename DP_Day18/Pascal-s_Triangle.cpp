class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         long long  n = numRows;
        if(n==0){
            vector<vector<int >> ans;
            return ans;
        }
        vector<vector<int>> ans;
        vector<int> t;
        t.push_back(1);
        ans.push_back(t);
        int filtil = 0;
        for(int i = 1;i < n;i++){
            vector<int> temp; temp.push_back(1);
            for(int j = 0;j < i-1;j++){
                 int l = ans[filtil][j]+ans[filtil][j+1];
                 temp.push_back(l);
            }
            temp.push_back(1);
            filtil+=1;
            ans.push_back(temp);
        } 
    return ans;
    }
};
