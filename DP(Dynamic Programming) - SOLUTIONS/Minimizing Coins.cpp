#include <bits/stdc++.h>
 
using namespace std;
#define push_back  push_back  
#define ll long long 
#define pll                 pvir<ll, ll>
#define mpp                  make_pair
long long mod = 1000000007;
 
 
 
 
ll helper(vector<ll>&arr,int i,ll tar,vector<vector<ll>>&dp){
    ll n = arr.size();
    if(tar<0){
        return 1e18;
    }
if(i>=n){
    if(tar==0){
        return 0;
    }
    return 1e18;
}
if(dp[i][tar]!=-1){
    return dp[i][tar];
}
 
ll p1 = helper(arr,i+1,tar,dp);
ll p2 = helper(arr,i,tar-arr[i],dp)+1;
 
return  dp[i][tar] = min(p1,p2);
 
}
 
int main(){
 
#ifndef ONLINE_JUDGE
 
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
 
 
 
 
 
int tt = 1;
 
 
  while(tt--){
 
long long  n;
cin>>n;
 
long long  tar;
cin>>tar;
vector<ll>arr(n);
for(int i =0;i<n;i++){
    cin>>arr[i];
}
 
 
 //vector<vector<ll>>dp(n+1,vector<ll>(tar+1,1e18));
//ll ans = helper(arr,0,tar,dp);
vector<ll>curr(tar+1,1e18);
vector<ll>prev(tar+1,1e18);
 
//for(int i =0;i<=n;i++){
curr[0] = prev[0]= 0;
//}
 
 
for(int i = n;i>=0;i--){
    for(int j = 1;j<=tar;j++){
 
 
// ll p1 = helper(arr,i+1,tar,dp);
// ll p2 = helper(arr,i,tar-arr[i],dp)+1;
 
// return  dp[i][tar] = min(p1,p2);
 
ll p1 = 1e18;
if(i+1<n){
p1 = prev[j];
}
 
 
 
ll p2 = 1e18;
if(i<n &&j-arr[i]>=0){
p2 = curr[j-arr[i]]+1;
}
 
curr[j] = min(p1,p2);
 
 
 
    }
 
    prev= curr;
}
 
 
 
ll ans = curr[tar];
if(ans>=1e18){
    cout<<-1<<endl;
}
else{
cout<<ans<<endl;
}
 
}
 
}
