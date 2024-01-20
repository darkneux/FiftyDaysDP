class Solution {
public:
  
    int numTeams(vector<int>& rating) {
        int n = rating.size();
       int dp1[n];
       int dp2[n];
       for(int i = n-1;i >=0 ;i--){
           int count = 0;
           for(int j = i+1;j < n;++j){
             if(rating[i] < rating[j])count++;
           }
           dp1[i]=count;
       }
       for(int &val : dp1)cout<<val<<" ";cout<<endl;

       for(int i = 0;i < n;++i){
           int count=0;
           for(int j=0;j < i;++j){
               if(rating[j] > rating[i])count++;
           }
           dp2[i] = count;
       }
       for(int &val:dp2)cout<<val<<" ";cout<<endl;

       int ans = 0;
       for(int i = 0;i < n;++i){
           for(int j = i+1;j < n;++j){
               if(rating[i] < rating[j])ans+=dp1[j];
               if(rating[i] > rating[j])ans+=dp2[i];
               
           }
       }
    
       return ans;

    }
};
