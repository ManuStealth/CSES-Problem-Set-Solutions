#include <bits/stdc++.h>
 
using namespace std;
#define push_back  push_back  
#define ll long long 
#define pll                 pvir<ll, ll>
#define mpp                  make_pair
//long long mod = 1e9+7;
 
 
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
 
int helper(vector<vector<int>> &mat,int i,int j,int x,int y,vector<vector<char>>&ans){
int n = mat.size();
int m = mat[0].size();
   
   bool flag = false;
 
 
 
 
queue< pair<int,int>  >q;
 
 
 
 
int step = 1;
 
q.push({i,j});
 
vector<vector<int>>vis(n,vector<int>(m,0));
vis[i][j] = 1;
 
while(!q.empty()){
 
   
   int val_x = q.front().first;
   int val_y = q.front().second;
q.pop();
 
if(val_x==x && val_y==y){
//  cout<<"YES"<<endl;
//  cout<<s.size()<<endl;
// flag = true;
 
//   for(int k = 0;k<s.size();k++){
//     cout<<s[k];
//   }
//   break;
 
return 1;
}
 
 
for(int k =0;k<4;k++){
int new_x = val_x  + dir[k][0];
int new_y = val_y  + dir[k][1];
 
if(new_x >=n || new_y>=m || new_y<0 || new_x<0||mat[new_x][new_y]==0||  vis[new_x][new_y] == 1){
    continue;
}
else{
    
 
    char curr ;
 
    if(k==0){
    curr = 'D';
    }
    else if(k==1){
 curr = 'R';
    }
    else if(k==2){
 curr = 'U';
    }
    else{
        curr = 'L';
     }
 
 
     ans[new_x][new_y] = curr;
 
 
     q.push({new_x,new_y});
     vis[new_x][new_y] = 1;
 
 
}
 
 
}
 
 
 
 
}
 
 
 
 
   if(!flag){
   //cout<<"NO";
 
    return 0;
   }
 
return 1;
}
 
 
void path(vector<vector<char>>&ans,int i,int j,int x,int y,string &res){
 
 
 
while(i!=x || j!=y){
 
    res += ans[i][j]; 
 
if(ans[i][j]=='L'){
 j++;
}
else if(ans[i][j]=='R'){
j--;
}
else if(ans[i][j]=='U'){
i++;
}
else if(ans[i][j]=='D'){
i--;
}
 
}
 
 
//return res;
 
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
int s_x,s_y,e_x,e_y;
 
for(int i  =0;i<n;i++){
    for(int j =0;j<m;j++){
    char x ;
cin>>x;
 
 
 
if(x=='#'){
mat[i][j] = 0;
}
else if(x=='.'){
    mat[i][j] = 1;
}
else if(x=='A'){
s_x = i;
s_y  = j;
   mat[i][j] = 2;
}
else{
e_x = i;
e_y  = j;
   mat[i][j] = 2;
}
 
}
}
 
 
vector<vector<char>>ans(n,vector<char>(m,'.'));
 
int flag = helper(mat,s_x,s_y,e_x,e_y,ans);
 
 
if(!flag){
cout<<"NO";
}
else{
cout<<"YES"<<endl;
 
// for(int i =0;i<ans.size();i++){
//     for(int j =0;j<ans[0].size();j++){
//         cout<<ans[i][j]<<" ";
//     }
//     cout<<endl;
// }
 
string res = "";
path(ans,e_x,e_y,s_x,s_y,res);
reverse(res.begin(),res.end());
cout<<res.size()<<endl;
cout<<res<<endl;
 
}
 
 
 
}
 
}
