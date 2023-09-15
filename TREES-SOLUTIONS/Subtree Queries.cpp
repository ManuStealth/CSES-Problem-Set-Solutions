TOPIC - Segment Tree + lazy propagation (no need - Just for practice) + Euler Tour technique


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
vector<ll>start(N);
vector<ll>finish(N);
vector<ll>timestamp(2*N);
ll timer ;
 
 
 
 
 
void dfs(ll src,ll par){
   
   start[src] = timer;
   timestamp[timer] =src;
   timer++;
 
 
for(auto child : g[src]){
    if(child == par){
        continue;
    }
 
 dfs(child,src);
 
}
 
 
finish[src] = timer;
timestamp[timer] =src;
timer++;
 
 
 
}
 
class ST{
 
vector<ll>tree,lazy;
 
public:
 
ST (ll n){
  
tree.resize(4*n);
lazy.resize(4*n);
}
 
void build(ll ind,ll low,ll high,vector<ll> &arr,vector<ll> &pnts){
 
if(low==high){
    tree[ind] = pnts[arr[low]];
    
    return;
}
 
 
 
ll mid  = low+(high-low)/2;
 
build(2*ind+1,low,mid,arr,pnts);
build(2*ind+2,mid+1,high,arr,pnts);
 
tree[ind]  = tree[2*ind+1] + tree[2*ind+2];
 
}
 

 
 
void update(ll ind ,ll low,ll high ,ll l ,ll r,ll val){
 
if(lazy[ind]!=0){
 
  tree[ind] += (high-low+1)*lazy[ind];
 
 if(low!=high){
  
    lazy[2*ind+1] += lazy[ind];
     lazy[2*ind+2] += lazy[ind];
 }
 
lazy[ind] = 0;
 
}
 
// no overlap
// return 
if(l>high || r<low){
 
return;
}
 
//complete ovelap
 
if(low>=l && high<=r){
    tree[ind] += (high-low+1)*val;
    
  if(low!=high){
    lazy[2*ind+1] += val;
    lazy[2*ind+2] +=val;
  }
 
  return ;
 
}
 
 
ll mid = (low+high)/2;
 
update(2*ind+1,low,mid,l,r,val);
update(2*ind+2,mid+1,high,l,r,val);
 
tree[ind] = tree[2*ind+1]+tree[2*ind+2];
 
 
}
 
ll query(ll ind,ll low,ll high,ll l ,ll r){
 
 
if(lazy[ind]!=0){
 
  tree[ind] += (high-low+1)*lazy[ind];
 
 if(low!=high){
  
    lazy[2*ind+1] += lazy[ind];
     lazy[2*ind+2] += lazy[ind];
 }
 
lazy[ind] = 0;
 
}
 
 
 // no overlap
 
    if(l>high || r<low){
        return 0;
    }
// complete overlap
 
    if(low>=l && high<=r){
        return tree[ind];
    }
 
    ll mid = low+(high-low)/2;
 
    ll left = query(2*ind+1,low,mid,l,r);
    ll right = query(2*ind+2,mid+1,high,l,r);
 
    return left+right;
 
}
 
};
 
 
 
int main(){
 
#ifndef ONLINE_JUDGE
 
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
 
 
 int tt = 1;
 
int mod = 1e9+7;
 
 
 while(tt--){
 
ll n,q;
 
cin>>n>>q;
 
vector<ll>pnts(n+1,0);
 
for(int i =1;i<=n;i++){
    cin>>pnts[i];
}
 
 
g = vector<vector<ll>>(n+1);
 
 
g[0].push_back(1);
g[1].push_back(0);
 
 
for(int i  = 1;i<=n-1;i++){
   ll u,v;
   cin>>u>>v;
 
   g[u].push_back(v);
   g[v].push_back(u);
}
 
timer = 1;
start = vector<ll>(n+1);
finish = vector<ll>(n+1);
timestamp = vector<ll>(2*n+1);
 
dfs(1,0);
 
// for(int i =1;i<=2*n;i++){
//         cout<<timestamp[i]<<" ";
// }
// cout<<endl;
ST st(2*n+1);
 
st.build(0,1,2*n,timestamp,pnts);
 
for(int i =0;i<q;i++){
  
  int type;
  cin>>type;
 
  if(type==1){
ll node,val;
cin>>node>>val;
ll diff = val-pnts[node];
pnts[node] = val;
 
ll l = start[node];
ll r = finish[node];
 
    st.update(0,1,2*n,l,l,diff);
    st.update(0,1,2*n,r,r,diff);
 
 
  }
  else{
    
    ll node;
    cin>>node;
 
   ll l = start[node];
   ll r = finish[node];
 
   cout<<st.query(0,1,2*n,l,r)/2<<endl;
 
  }
 
 
}
 
 
 
 
 
 
 
}
 
}
