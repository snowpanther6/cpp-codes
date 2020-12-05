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


void solve() {

    string s;
    cin>>s;
    int n = s.length();
    int dp[2][n+1];
    string s2=s;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0) dp[i%2][j]=0;
            else if(s[i-1]==s2[j-1]){
                dp[i%2][j] = 1 + dp[(i+1)%2][j-1];
            }
            else dp[i%2][j] = max(dp[(i+1)%2][j],dp[i%2][j-1]);
        }
    }
    cout<<dp[n%2][n];
}


int32_t main()
{
    FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}
