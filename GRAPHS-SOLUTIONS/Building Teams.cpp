  
#include <bits/stdc++.h>
 
using namespace std;
// #define pb  push_back  
#define ll long long 
#define pll                 pvir<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
int helper(int node,vector<int>&stor,vector<vector<int>>&adj){
 
 
queue<int>q;
 
q.push(node);
stor[node] = 1;
 
 
while(!q.empty()){
 
int curr = q.front();
q.pop();
 
 
for(int i =0;i<adj[curr].size();i++){
 
int color ;
if(stor[curr]==1){
    color = 2;
}
else{
color  = 1;
}
 
if(stor[adj[curr][i]]==-1){
   stor[adj[curr][i]] = color;
q.push(adj[curr][i]);
}
else if(stor[adj[curr][i]]!=color){
   return false;
}
 
 
}
 
 
 
 
}
 
return true;
 
 
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
 
bool flag = true;
vector<int>stor(n+1,-1);
 
 
for(int i =1;i<=n;i++){
 
if(stor[i]==-1){
 
int check = helper(i,stor,adj);
 
if(!check){
    flag = false;
    break;
}
 
}
 
}
 
if(flag){
 
for(int i = 1;i<stor.size();i++){
    cout<<stor[i]<<" ";
}
 
}
else if(!flag){
cout<<"IMPOSSIBLE";
}
 
 
 
}
 
}
