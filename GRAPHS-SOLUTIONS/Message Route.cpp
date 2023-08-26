#include <bits/stdc++.h>
 
using namespace std;
// #define pb  push_back  
#define ll long long 
#define pll                 pvir<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
 
bool helper(vector<vector<int>>&adj,vector<int>&par){
  
  int target = adj.size()-1;
 
  vector<int>vis(adj.size(),0);
 
  queue< int>q;
 
q.push(1);
vis[1] = 1;
 
bool flag = false;
 
while(!q.empty()){
 
int curr = q.front();
 
q.pop();
 
if(curr==target){
 
flag = true;
break;
 
}
 
 
for(int i =0;i<adj[curr].size();i++){
 
if(vis[adj[curr][i]]==0){
 
par[adj[curr][i]] = curr;
 
vis[adj[curr][i]] = 1;
q.push(adj[curr][i]);
 
 
}
 
 
}
 
 
}
 
return flag;
 
 
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
 
vector<int>par(adj.size(),-1);
 
bool flag = helper(adj,par);
 
 
if(flag){
 
int node = n;
 
vector<int>stor;
 
while(par[node]!=-1){
    stor.push_back(node);
node = par[node];
}
 
stor.push_back(1);
cout<<stor.size()<<endl;
 
for(int i =stor.size()-1;i>=0;i--){
    cout<<stor[i]<<" ";
}
 
 
 
}
else if(!flag){
cout<<"IMPOSSIBLE";
}
 
 
 
}
 
}
