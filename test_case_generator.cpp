
void solve(){
    srand(time(0));
    // int t = (rand() % 5) + 1;
    int t = 10;
    cout<<t<<endl;
    while(t--){
        int n = (rand() % (100000-10000+1)) + 10000;
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            int val = (rand() % (100000-10000+1)) + 10000;
            cout<<val<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            int val = (rand() % (100000-10000+1)) + 10000;
            cout<<val<<" ";
        }
        cout<<endl;
    }
    
}
