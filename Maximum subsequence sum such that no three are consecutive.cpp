#include<bits/stdc++.h>
#define int long long int
using namespace std;

void FIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int dp[1005];

int func(int n,int a[]){
	if(n<=-1) return 0;
	if(dp[n]!=-1) return dp[n];

	int x = a[n] + ((n-1>=0)?a[n-1]:0) + func(n-3,a);
	int y = a[n] + func(n-2,a);
	int z = func(n-1,a);

	return dp[n] = max(x,max(y,z));
}

int32_t main()
{
	FIO();
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	dp[n];
	
	for(int i=0;i<n;i++) dp[i]=-1;
	cout<<func(n-1,a);
	
	return 0;
}
