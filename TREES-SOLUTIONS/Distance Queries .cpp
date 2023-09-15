#include <bits/stdc++.h>
 
using namespace std;
// #define pb  push_back  
#define ll long long 
#define pll                 pair<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
 
#define pii pair<ll,ll>
 
int N = 2e5+1;
 
vector<vector<int>>g(N);
vector<int>depth(N,0);
vector<vector<int>>up(20,vector<int>(N,0));
 
void dfs(int src,int par){
    depth[src] = depth[par]+1;
 
    up[0][src] = par;
 
    for(int i = 1;i<20;i++){
        up[i][src] = up[i-1][up[i-1][src]];
    }
 
 
    for(auto child:g[src]){
        if(child==par){
            continue;
        }
 
        dfs(child,src);
    }
 
}
 
 
int lca(int u,int v){
 
if(depth[u]>depth[v]){
    swap(u,v);
}
 
int diff = depth[v]-depth[u];
 
for(int i = 0;i<20;i++){
    if(diff&(1<<i)){
        v = up[i][v];
    }
}
 
if(u==v){
    return u;
}
 
for(int i =19;i>=0;i--){
    if(up[i][v]!=up[i][u]){
        v = up[i][v];
        u = up[i][u];
    }
}
 
return up[0][u];
 
 
}
 
 
int main(){
 
#ifndef ONLINE_JUDGE
 
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
 
 
 int tt = 1;
 
int mod = 1e9+7;
 
 
 while(tt--){
 
int n,q;
cin>>n>>q;
 
g[0].push_back(1);
g[1].push_back(0);
for(int i =1;i<=n-1;i++){
   int u,v;
   cin>>u>>v;
 
 g[u].push_back(v);
 g[v].push_back(u);
 
}
 
dfs(1,0);
 
 
for(int i = 0;i<q;i++){
    int u,v;
    cin>>u>>v;
 
    int LCA = lca(u,v);
 
  cout<<depth[u]+depth[v]-2*depth[LCA]<<endl;
 
}
 
 
 
}
 
}
