class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();

        int i = 1;
        int ans = 0;
        while(i < n){
            int minv = neededTime[i-1];
            if(colors[i] != colors[i-1]){
              i++;continue;
            }else{
                i--;
                // cout<<i;
                int j = i;
                int totalwin = 0;
                while(j < n){
                    if(colors[i]!= colors[j])break;
                    totalwin+=neededTime[j];
                    minv = max(minv,neededTime[j]);
                    j++;
                }
                
               ans+=(totalwin - minv);
               i = j;
            //    cout<<"   "<<i<<endl;
            }
            
        }
        return ans;
        
    }
};
