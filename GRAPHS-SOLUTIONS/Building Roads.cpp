
#include <bits/stdc++.h>
 
using namespace std;
#define push_back  push_back  
#define ll long long 
#define pll                 pvir<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
 
void bfs(int node , vector<vector<int>>&adj,vector<int>&vis){
 
if(vis[node]==1){
    return;
}
 
vis[node] = 1;
 
 
for(int i =0;i<adj[node].size();i++){
 
bfs(adj[node][i],adj,vis);
 
}
 
 
 
 
 
}
 
 
int main(){
 
#ifndef ONLINE_JUDGE
 
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
 
 
 
 
 
 int tt = 1;
 
int mod = 1e9+7;
 
 
 while(tt--){
 
int  n, m;
cin>>n>>m;
 
vector<vector<int>>adj(n+1);
 
 
for(int i =0;i<m;i++){
    int f,s;
    cin>>f>>s;
 
    adj[f].push_back(s);
    adj[s].push_back(f);
}
 
int grp =0;
 
vector<int>vis(n+1,0);
vector<int>stor;
 
for(int i =1;i<=n;i++){
if(vis[i]==0){
  
    bfs(i,adj,vis);
    stor.push_back(i);
    grp++;
}
 
}
 
 
cout<<grp-1<<endl;
for(int i =0;i<stor.size()-1;i++){
    cout<<stor[i]<<" "<<stor[i+1]<<endl;
}
 
 
}
 
}
