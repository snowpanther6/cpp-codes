#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp12            make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pq123           priority_queue<int>
#define pqr1            priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void FIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int modInv(int a, int b, int m) {int res = 1; a = a % m; while (b > 0) {if (b & 1) {res = (res * a) % m;} a = (a * a) % m; b = b >> 1;} return res;}

int dp[1001];

int func(int n,int x,int y,int tog){
    if(n==0){
        if(tog==2) return 1;
        else return 0;
    }
    if(dp[n]!=-1) return dp[n];
    int a=0,b=0,c=0;
    if(n-1>=0) a = func(n-1,x,y,3-tog);
    if(n-x>=0) b = func(n-x,x,y,3-tog);
    if(n-y>=0) c = func(n-y,x,y,3-tog);

    return dp[n] = a or b or c;
}

void solve() {

    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    memset(dp,-1,sizeof(dp));
    if(func(n,x,y,1)) cout<<"A";
    else cout<<"B";
}


int32_t main()
{
    FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}
