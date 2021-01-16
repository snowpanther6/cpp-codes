#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> minST(int arr[],int n){
  int log2N = log2(n);
  vector<vector<int>> sparse(log2N+1,vector<int>(n));
  for(int i = 0; i < n; i++)
    sparse[0][i] = arr[i];
    
  for(int i = 1; i <= log2N; i++){
      int end = n - (1<<i) + 1; 
      for(int j = 0; j < end; j++){
        sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j + (1<<(i-1))]);
      }
  }
  return sparse;
}
vector<vector<int>> maxST(int arr[],int n){
  int log2N = log2(n);
  vector<vector<int>> sparse(log2N+1,vector<int>(n));
  for(int i = 0; i < n; i++)
    sparse[0][i] = arr[i];
    
  for(int i = 1; i <= log2N; i++){
      int end = n - (1<<i) + 1; 
      for(int j = 0; j < end; j++){
        sparse[i][j] = max(sparse[i-1][j], sparse[i-1][j + (1<<(i-1))]);
      }
  }
  return sparse;
}

int min(vector<vector<int>> &st , int n, int a, int b){
    int p = log2(b-a+1);
    int end = b - (1<<p) +1;
    return min(st[p][a], st[p][end]);
}
int max(vector<vector<int>> &st , int n, int a, int b){
    int p = log2(b-a+1);
    int end = b - (1<<p) +1;
    return max(st[p][a], st[p][end]);
}

int solveTestCase() {
    int m,n;
    string s;
    cin>>m>>n>>s;
    int a[m+1] = {};
    for(int i = 1; i <= m; i++){
        if(s[i-1] == '+')
            a[i] = a[i-1]+1;
        else
            a[i] = a[i-1]-1;
    }
    vector<vector<int>> maxStb = maxST(a,m+1);
    vector<vector<int>> minStb = minST(a,m+1);
 
     int min1 = min(minStb,m+1,0,l-1);
     int max1 = max(maxStb,m+1,0,l-1);

    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solveTestCase();
}
