TOPIC - Binary Lifting + Difference Tree (similar to difference Array)
# DIFFERENCE ARRAY TECHNIQUE ON TREES


#include <bits/stdc++.h>
 
using namespace std;
// #define pb  push_back  
#define ll long long 
#define pll                 pair<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
 
#define pii pair<ll,ll>
 
ll N  = 2e5+1;
 
vector<vector<ll>>g(N);
vector<vector<ll>>up(20,vector<ll>(N,0));
vector<ll>depth(N,0);
 
 
 
 
void dfs(ll src,ll par){
    depth[src] = depth[par]+1;
 
   up[0][src] = par;
  
   
 
 for(int i = 1;i<20;i++){
 
 up[i][src] = up[i-1][up[i-1][src]];
 
 }
 
 
for(auto child : g[src]){
    if(child == par){
        continue;
    }
 
 dfs(child,src);
 
}
 
 
}
 
ll lca(ll u,ll v){
    if(depth[u]>depth[v]){
        swap(u,v);
    }
 
 
    ll diff = depth[v]-depth[u];
  
  for(int i =0;i<20;i++){
    if(diff & (1<<i)){
        v = up[i][v];
    }
  }
 
 
  if(v==u){
    return u;
  }
 
  for(int i =19;i>=0;i--){
    if(up[i][u]!=up[i][v]){
        v = up[i][v];
        u = up[i][u];
    }
  }
 
 
  return up[0][u];
 
 
 
}
 
int DFS(int src,int par,vector<int>&stor,vector<int>&temp){
 
 if(g[src].size()==0){
  return 0;
 }
 
 for(auto child : g[src]){
 
 if(child==par){
    continue;
 }
 
 
 
stor[src] += DFS(child,src,stor,temp);
 
 
 }
 
stor[src]+=temp[src];
  
 
  return stor[src];
 
 
}
 
 
int main(){
 
#ifndef ONLINE_JUDGE
 
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
 
 
 int tt = 1;
 
int mod = 1e9+7;
 
 
 while(tt--){
 
g = vector<vector<ll>>(N);
up = vector<vector<ll>>(20,vector<ll>(N,0));
depth  = vector<ll>(N,0);
 
 
int n,m;
cin>>n>>m;
 
g[0].push_back(1);
g[1].push_back(0);
 
for(int i = 1;i<=n-1;i++){
    int u,v;
    cin>>u>>v;
   g[u].push_back(v);
   g[v].push_back(u);
 
}
 
 
 
dfs(1,0);
 
vector<ll>ans(n+1,0);
 
 
vector<int>temp(n+1,0);
 
for(int i =0;i<m;i++){
    ll u,v;
    cin>>u>>v;
  
 ll LCA = lca(u,v);
 
 
temp[u]++;
temp[v]++;
temp[LCA]--;
 
 
if(up[0][LCA]!=0){
    temp[up[0][LCA]]--;
}
 
 
 
}
 
vector<int>stor(n+1,0);
 
DFS(1,0,stor,temp);
 
 
for(int i = 1;i<=n;i++){
    cout<<stor[i]<<" ";
 
}
 
 
 
 
 
}
 
}
