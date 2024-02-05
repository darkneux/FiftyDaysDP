#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x,ans=1e9;
	cin>>n>>x;
	int coind[n],dp[1][x+1];
	for(int i = 0;i < n;++i) cin>>coind[i];
	for(int j = 0;j <=x;++j) dp[0][j]=1e9;
	dp[0][0]=0;

	for(int i = 0;i < n;++i){
		for(int j = 1;j <=x;++j){
			if(j >= coind[i]){
				dp[0][j] = min(dp[0][j],dp[0][j-coind[i]]+1);
			}
			if(j==x)ans = min(ans,dp[0][x]);
		}
		// for(int j = 0;j <= x;++j){
		// 	cout<<dp[0][j]<<" ";
		// }
		// cout<<endl;
	}


	if(ans == 1e9)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
