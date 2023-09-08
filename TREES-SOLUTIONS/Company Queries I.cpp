TOPIC - BINARY LIFTING

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
vector<vector<int>>up(20,vector<int>(N,0));
vector<int>depth(N,0);


void dfs(int src,int par){


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


int helper(int node,int k){
 

for(int i =0;i<20;i++){
    if(k&(1<<i)){
        node = up[i][node];
    }
    if(node==0){
        return -1;
    }
} 

return node;
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

vector<int>arr(n+1);
 arr[0] = 0;
for(int i = 1;i<n;i++){
 cin>>arr[i];
}



for(int i = 1;i<=n;i++){
   int par = arr[i-1];
   int child = i;

g[par].push_back(child);
g[child].push_back(par);

}

dfs(1,0);

for(int i =0;i<q;i++){
    int u,v;
    cin>>u>>v;
  
  cout<<helper(u,v)<<endl;
    
}



}

}
