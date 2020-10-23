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

void dfs(int src,vector<vector<pair<int,int> > > &g,vector<int> &vis,vector<int> &ord){
    vis[src]=1;
    for(auto x:g[src]){
        if(!vis[x.first]){
            dfs(x.first,g,vis,ord);
        }
    }
    ord.pb(src);
}

void solve(){
    
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>> > g(v);
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].pb(make_pair(y,z));
    }
    vector<int> ord;
    vector<int> vis(v);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,g,vis,ord);
        }
    }
    reverse(ord.begin(),ord.end());
    vector<int> dist(v,INT_MIN);
    dist[1]=0;
    for(int i=0;i<v;i++){
        if(dist[ord[i]]!=INT_MIN){
            for(auto x:g[ord[i]]){
                int y = x.first;
                int w = x.second;
                dist[y] = max(dist[y],dist[ord[i]]+w);
            }
        }
    }
    for(int i=0;i<ord.size();i++) cout<<ord[i]<<" ";
        cout<<endl;
    for(int i=0;i<dist.size();i++) cout<<dist[i]<<" ";
}
    

int32_t main()
{
    FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
