#include <bits/stdc++.h>
 
using namespace std;
#define push_back  push_back  
#define ll long long 
#define pll                 pvir<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
 
 
void helper(vector<vector<int>> &mat,int i,int j){
int n = mat.size();
int m = mat[0].size();
   
   queue<pair<int,int>>q;
q.push({i,j});
 
   while(!q.empty()){
int x = q.front().first;
int y  = q.front().second;
q.pop();
 
 
for(int k= 0;k<4;k++){
    int new_x = x + dir[k][0];
    int new_y = y + dir[k][1];
 
if(new_x>=n || new_y>=m || new_x<0 || new_y<0 || mat[new_x][new_y]==0){
    continue;
} 
else{
  q.push({new_x,new_y});
  mat[new_x][new_y] = 0;
}
 
}
 
     
    
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
 
int n,m;
cin>>n>>m;
 
vector<vector<int>>mat(n,vector<int>(m));
 
for(int i  =0;i<n;i++){
    for(int j =0;j<m;j++){
    char x ;
cin>>x;
 
if(x=='#'){
mat[i][j] = 0;
}
else{
    mat[i][j] = 1;
}
 
    }
}
 
 
int ans = 0;
 
for(int i =0;i<n;i++){
    for(int j = 0;j<m;j++){
        if(mat[i][j]==1){
            ans++;
            helper(mat,i,j);
        }
    }
}
 
 
cout<<ans;
 
 
}
 
}
