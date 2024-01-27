class Solution {
public:
    
    int kInversePairs(int n, int k) {
        int MD = 1e9+7;
        vector<int> last (k+1,0);
        vector<int> curr (k+1,0);
        last[0]=1;
        for(int i =1;i <= n;++i){
            
            long long swsum = 0;
            for(int j = 0;j <= k;++j){
                if(j >= i) swsum = (swsum - last[j-i] + MD) % MD;
                swsum = (swsum +last[j] )%MD ;
                curr[j] = swsum;
            }
            last = curr;
            // for(auto & it : curr)cout<<it<<" ";
            // cout<<endl;
        }
        return last[k];
    }
};

