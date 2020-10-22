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
    int res[v];
    bool available[v];
    res[0]=0;
    for(int i=1;i<v;i++) res[i] = -1;
    for(int i=0;i<v;i++) available[i] = false;

    int cn = 0;
    for(int i=1;i<v;i++){
        for(auto x:g[i]){
            if(res[x]!=-1){
                available[res[x]] = true;
            }
        }

        int cr;
        for(cr=0;cr<v;cr++){
            if(available[cr] == false){
                break;
            }
        }

        res[i] = cr;
        cn = max(cn,cr+1);

        for(auto x:g[i]){
            if(res[x]!=-1){
                available[res[x]] = false;
            }
        }
    }
    cout<<cn<<endl;
    for(int i=0;i<v;i++) cout<<res[i]<<" ";

}
    

int32_t main()
{
    FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
