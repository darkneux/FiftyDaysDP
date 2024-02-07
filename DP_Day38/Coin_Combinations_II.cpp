#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	int coind[n];long long dp[1][x+1];
	for(int i =0;i < n;++i)cin>>coind[i];
	for(int j =0;j <=x;++j)dp[0][j]=0;
	dp[0][0]=1;
	for(int i = 0;i < n;++i){
		for(int j = 1;j <= x;++j){
			if(j >= coind[i]){
			dp[0][j] = (dp[0][j] + dp[0][j-coind[i]])%1000000007;
			}
		}
		// for(int j = 0;j <= x;++j)cout<<dp[0][j]<<"  ";
		// cout<<endl;
        }
	cout<<dp[0][x]<<endl;
	return 0;
}
