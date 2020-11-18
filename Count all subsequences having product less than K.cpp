#include<bits/stdc++.h>
#define int long long int
using namespace std;

void FIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int32_t main()
{
	FIO();
	
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++) cin>>a[i];
	int k;
	cin>>k;

	int dp[k+1][n+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1];

			if(a[j]<=i and a[j]>0){
				dp[i][j]+= dp[i/a[j]][j-1] + 1;
			}
		}
	}
	cout<<dp[k][n];
	
	return 0;
}
