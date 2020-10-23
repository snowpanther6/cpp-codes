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

int n = 5;
vector<int> disc(n);
vector<int> low(n);
int tim;
set<int> art_p;
vector<pair<int,int> > art_b;

void dfs(int src,int par,vector<vector<int> > g){
    disc[src] = low[src] = tim++;
    int no_child = 0;
    for(auto x:g[src]){
        if(!disc[x]){
            dfs(x,src,g);
            no_child++;
            low[src] = min(low[src],low[x]);
            if(par!=-1 and low[x] >= disc[src]){
                art_p.insert(src);
            }
            if(low[x] > disc[src]){
                art_b.pb({src,x});
            }
        }
        else if(x!=par){
            //backedge
            low[src] = min(low[src],disc[x]);
        }
    }
    if(par == -1 and no_child>=2){
        art_p.insert(src);
    }
}

void solve(){
    
    int e;
    cin>>e;
    vector<vector<int> > g(n);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    tim = 1;
    dfs(0,-1,g);
    for(auto x:art_p) cout<<x<<" ";
    cout<<endl;
    for(int i=0;i<art_b.size();i++) cout<<art_b[i].first<<" "<<art_b[i].second<<endl;
}
    

int32_t main()
{
    FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
