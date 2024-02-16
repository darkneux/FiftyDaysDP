class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int maxval = prices[prices.size()-1];
        for(int i = prices.size()-1;i>=0;i--){
            maxprofit = max(maxprofit,maxval-prices[i]);
            maxval = max(maxval,prices[i]);
           // cout<<maxprofit<<" ";
        }
        return maxprofit;
    }
};
