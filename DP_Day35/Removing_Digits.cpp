#include <bits/stdc++.h>
using namespace std;

int main(){
    int INF = 1e9;
    int n, dp[1000001];
    cin>>n;
    fill(dp+1, dp+n+1, INF);

    for(int i = 1; i <= n; i++){
        int d = i;
        while(d > 0){
            if(d%10 != 0)
                dp[i] = min(dp[i], dp[i-(d%10)]+1);
            d /= 10;
        }
    }

    cout<<dp[n]<<endl;
}