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

void FIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int modInv(int a,int b,int m){int res=1;a=a%m;while(b>0){if(b&1){res=(res*a)%m;}a=(a*a)%m;b=b>>1;}return res;}

int f=0;
void dfs(int src,int par,int col,vector<vector<int> > &g,vector<int> &vis){
    vis[src] = col;
    for(auto x:g[src]){
        if(vis[x]==-1){
            dfs(x,src,3-col,g,vis);
        }
        else if(x!=par and col == vis[x]){
            f=1;
            break;
        }
    }
}

void solve(){
    
    int v,e;
    cin>>v>>e;
    vector<vector<int> > g(v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    f=0;
    vector<int> vis(v,-1);
    dfs(0,0,1,g,vis);
    if(f) cout<<"Not Bipartite";
    else cout<<"Bipartite";

}
    

int32_t main()
{
    FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
